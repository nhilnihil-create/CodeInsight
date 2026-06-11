#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define vl vector<ll>
#define pll pair<ll,ll>
#define mll map<ll, ll> 
#define rep(i,a)  for(ll i= 0;i < a;i++)
#define rep1(i,a) for(ll i= 1;i < a;i++)
#define foi(i, a, b)    for(ll i = a; i<b ; i++)
#define fod(i, a, b)    for(ll i = a; i>=b ; i--)
#define pb push_back
#define sz(v) v.size()
#define all(a) a.begin(), a.end()
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define MAX 1e6+5
#define MOD 1000000007
#define el "\n"
const ll INF = 2e9+5;
  
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
ll isPrime(ll n){if(n<=3) return 1;if(n%2==0||n%3==0) return 0;
for(ll j=5;j*j<=n;j+=6){if(n%j == 0||n%(j+2) == 0) return 0;}return 1;}
 
using namespace std;
void solve(){
   ll h,w;
   cin>>h>>w;
   char arr[h][w];
   rep(i,h)rep(j,w){
      char c; 
      cin>>c;
      arr[i][j] = c;
   }
   // rep(i,h)rep(j,w)cout<<arr[i][j];
   vector<vector<ll>> dp(h,vector<ll>(w,0));
   ll i=0,j=0;
   while(i<h&&arr[i][0] != '#') {dp[i][0] = 1;i++;}
   while(j<w&&arr[0][j] != '#') {dp[0][j] = 1;j++;}
   rep1(i,h)rep1(j,w){
      if(arr[i][j] == '#') continue;
      else if(arr[i][j-1] == '#')  dp[i][j] = dp[i-1][j];
      else if(arr[i-1][j] == '#')  dp[i][j] = dp[i][j-1];
      else dp[i][j] = (dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD;
      dp[i][j] %= MOD;
   }
   cout<<dp[h-1][w-1];

}
 
int main() {
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r" , stdin);
      freopen("output.txt", "w" , stdout);
   #endif
   ios::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);   
   ll t;
   // cin>>t;
   t = 1;
   ll tc=0;
   while(tc++<t){
      // cout<<"Case #"<<tc<<": ";
      solve();
   }
   cerr<<"Time taken : "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}