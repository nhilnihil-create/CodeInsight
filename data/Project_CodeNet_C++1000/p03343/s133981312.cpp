#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
int n, k, q;
int a[2005];
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> n >> k >> q;
  vector<int> v;
  f(i,0,n)
    cin >> a[i], v.pb(a[i]);

  sort(v.begin(),v.end());
  v.resize(unique(v.begin(),v.end()) - v.begin());

  int ans = INT_MAX;
  for(auto x : v){
    int lo = x, hi = 2e9;
    while(lo<hi){
      int md = lo+(hi-lo)/2;
      int cnt = 0;
      for(int i = 0, j = 0; i < n; i = j){
        if(a[i] < x)j=i+1;
        else {
          int c = 0,cnt2=0;
          for(;j<n&&a[j]>=x;j++)c++,cnt2+=(a[j]<=md);
          cnt+=min(cnt2,max(0,c-k+1));
        }
      }
//      cout<<md<<' '<<cnt<<'\n';
      if(cnt>=q)
        hi = md;
      else
        lo = md + 1;
    }
    ans =min(ans,lo-x);
  }

  cout << ans << '\n';


  return 0;
}
