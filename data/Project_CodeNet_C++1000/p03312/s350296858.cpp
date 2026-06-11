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
ll sum[N+N];
int n;
ll getSum(int l, int r){
  return sum[r] - sum[l-1];
}
int getPartition(int l, int r){

  int lo = l, hi = r - 1;
  while(lo < hi){

    int md = lo + (hi - lo + 1) / 2;

    if(getSum(l,md) <= getSum(md+1,r))
      lo = md;
    else
      hi = md - 1;

  }

  return lo;
}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> n;

  f(i,1,n+1)cin >> sum[i], sum[i] += sum[i-1];
  ll ans = LLONG_MAX;
  f(i,2,n-1){

    int x = getPartition(1,i);
    int y = getPartition(i+1,n);

    for(int j = -5; j <= 5; j++){
      for(int k = -5; k <= 5; k++){
        if(x + j < 1 || x + j >= i)continue;
        if(y + k <= i || y + k >= n)continue;
        vector<ll> v = {getSum(1,x+j),getSum(x+j+1,i),getSum(i+1,y+k),getSum(y+k+1,n)};
        sort(v.begin(),v.end());
        ans = min(ans, v.back()-v[0]);
      }
    }

  }

  cout << ans << '\n';


  return 0;
}
