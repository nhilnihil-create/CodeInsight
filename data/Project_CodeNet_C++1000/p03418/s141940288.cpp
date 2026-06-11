#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;

const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    ll n, k;
  cin >> n >> k;

  if(k == 0) {
    cout << n*n << endl;
    return 0;
  }

  ll ans = 0;
  for(ll i = 1; i<=n ;i++) {
    if(i-1 >= k) {
      ans += n/i*(i-k);
      ans += max(0ll, (n%i) - k + 1);
    }
  }
  cout << ans << endl;
}