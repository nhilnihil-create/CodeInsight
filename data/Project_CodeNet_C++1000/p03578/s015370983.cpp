#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int n;
  cin >> n;
  vector<ll> d(n);
  rep(i,n) cin >> d[i];
  int m;
  cin >> m;
  vector<ll> t(m);
  rep(i,m) cin >> t[i];

  sort(d.begin(),d.end());
  sort(t.begin(),t.end());

  int id = 0;
  int it = 0;
  while(true){
    if(it == m) {
      cout << "YES" << endl;
      return 0;
    }
    if(id == n) {
      cout << "NO" << endl;
      return 0;
    }

    if (d[id] != t[it]) id++;
    else {
      it++;
      id++;
    }
  }

  return 0;
}
