  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   double dll ;

#define   mp make_pair
#define   pb push_back
#define   ff first 
#define   ss second
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   endl "\n" 
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);
ll n;
ll dp[200010];
vector<pll> arr;
ll recurse(ll idx) {
  if(idx == n - 1) return 1;
  ll &ans = dp[idx];
  if(ans != -1) return ans;
  ans = 1;
  ll tt = recurse(idx + 1);
  if(arr[idx].ss < arr[idx+1].ss) ans+= tt;
  return ans;  
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  arr.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> arr[i].ff;
    arr[i].ss = i;
  }
  sort(all(arr));
  memset(dp, -1, sizeof dp);
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
    ans = max(ans, recurse(i));
  }
  cout <<  n - ans << endl;
  return 0;
} //good night.