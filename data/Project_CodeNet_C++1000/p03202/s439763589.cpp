#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int a[N];
int n;

vector<pii> eli;
int cnt;

void add(int pos, int x){
  while(!eli.empty() && eli.back().fi >= pos){
    eli.pop_back();
  }
  eli.push_back(mp(pos, x));
  if(pos < cnt)
    eli.push_back(mp(pos + 1, 1));
}

bool solve(int k){
  eli.clear();
  eli.push_back(mp(1, 1));
  int idx;
  int ps;
  for(int i = 2; i <= n; i ++ ){
    cnt = a[i];
    while(eli.back().fi > a[i])
      eli.pop_back();
    if(a[i] > a[i - 1]){
      if(eli.back().se != 1){
        eli.push_back(mp(a[i - 1] + 1, 1));
      }
      continue;
    }
    else{
      idx = eli.size() - 1;
      ps = cnt;
      while(idx >= 0){
        if(eli[idx].se < k) break;
        ps = eli[idx].fi - 1;
        --idx;
      }
      if(idx == -1){
        return false;
      }
      add(ps, eli[idx].se + 1);
    }
  }
  return true;
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
  }
  int l=1, r=n;
  int m;
  while(l < r){
    m = (l + r) / 2;
    if(!solve(m))
      l = m + 1;
    else
      r = m;
  }
  cout << r << "\n";
  return 0;
}
