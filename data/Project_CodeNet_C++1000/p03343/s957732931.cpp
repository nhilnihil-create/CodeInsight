#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long int MOD = 1000000007;
const int N = 2001;
int n, k, q;
int a[N];
bool can(int mn, int mx){
  multiset<int> ss;
  for(int i = 0;i < k;i++)
    ss.insert(a[i]);
  int in = k;
  int l = 0;
  map<int, int> done;
  int qq = q;
  while(qq){
    auto it = ss.begin();
    if(*it >= mn && *it <= mx){
      done[*it]++;
      ss.erase(it);
      qq--;
      if(in != n)
        ss.insert(a[in++]);
      else
        break;
    }else{
      while(done[a[l]] != 0){
        done[a[l++]]--;
      }
      ss.erase(ss.find(a[l++]));
      if(in == n)
        break;
      ss.insert(a[in++]);
    }
  }
  return qq == 0;
}
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> k >> q;
  for(int i = 0;i < n;i++)
    scanf("%d", a + i);
  vector<int> vv(a, a + n);
  sort(vv.begin(), vv.end());
  int r = 0;
  int res = 2e9;
  for(int i = 0;i < n;i++){
    while(r < n && !can(vv[i], vv[r]))
      r++;
    if(r == n)break;

    res = min(res, vv[r] - vv[i]);
  }
  cout << res;
}

