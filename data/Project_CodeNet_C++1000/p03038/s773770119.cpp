#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> a(n), b(m), c(m);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  rep(i,m) cin >> b[i] >> c[i];

  vector<int> id(m);
  iota(id.begin(), id.end(),0);
  sort(id.begin(),id.end(),[&](int i, int j){
                             return c[i]>c[j];});

  ll sum = 0;
  ll k = 0;
  for(auto i : id){
    for(int j = 0; j < b[i]; j++){
      if(k >= n) break;
      sum += max(a[k++], c[i]);
    }
  }
  for(int i = k; i < n; i++) sum += a[i];
  cout << sum << endl;
}
