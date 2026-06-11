#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  int cur = 0;

  int m, k;
  cin >> m >> k;

  if(m<=1){
      if(k==0){
          f(i,0,m+1)cout<<i<<' '<<i<< ' ';
      } else cout << -1 << '\n';
  } else if((1 << m) > k){
    int buffer = 1 + (k == 1);
    vector<int> v;  v.pb(k);
    f(i,0,1<<m)if(i!=k)v.pb(i);
    v.pb(k);
    for(int i = (1<<m)-1;i>=0;--i)if(i!=k)v.pb(i);
    for(auto x:v)cout<<x<<' ';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}
