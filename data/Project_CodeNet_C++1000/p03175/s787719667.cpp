#include<bits/stdc++.h>
using namespace std;
//
typedef long double ld;
typedef long long int ll;
//
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define prq priority_queue<ll>;
#define vbs(xx,x) binary_search(all(xx),x)
#define vlb(xx,x) lower_bound(all(xx),x)
#define vub(xx,x) upper_bound(all(xx),x)
//
ll MOD=998244353;
ll M=1e9+7;
#define PI 3.1415926535897932384626433832795
ll llMAX=1000000000000000008;
ll llMIN=-1000000000000000008;
//
#define forx(i,j,n) for(ll i=j;i<n;i++)
#define fory(i,j,n) for(ll i=j;i>=n;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sn second
#define MEM(xx,yy) memset(xx,yy,sizeof(xx))
//
#define in(x) cin>>x
#define op(x) cout<<x
#define opnl(x) cout<<x<<"\n"
#define ops(x) cout<<x<<" "
#define nl cout<<"\n"
#define sp cout<<" "
#define flush fflush(stdout)
clock_t tim;
void showtime(){ tim=clock()-tim; cout<<" ===> "<<(ld)tim/CLOCKS_PER_SEC<<" seconds\n"; }
//
ll mul(ll mul_1,ll mul_2){ ll mul_t=((mul_1%MOD)*(mul_2%MOD)+MOD)%MOD; return mul_t; }
ll mul3(ll mul_1,ll mul_2,ll mul_3){ ll mul_t=mul(mul(mul_1,mul_2),mul_3)%MOD; return mul_t; }
ll add(ll add_1,ll add_2){ ll add_t=((add_1%MOD)+(add_2%MOD)+MOD+MOD)%MOD; return add_t; }
ll sub(ll sub_1,ll sub_2){ ll sub_r=1e15; ll sub_t=(((sub_1+sub_r)%MOD)-((sub_2+sub_r)%MOD)+sub_r)%MOD; return sub_t; }
ll pwm(ll x,ll y,ll p=M){ ll res=1; x=x%p; while(y>0){ if(y&1) res=(res*x)%p; y=y/2; x=(x*x)%p; } return res; } 
ll pw(ll x,ll y){ ll res=1; while(y>0){ if(y&1) res=(res*x); y=y/2; x=(x*x); } return res; } 
ll modinv(ll n){ return pwm(n, M-2, M); }
ll gcd(ll num1,ll num2){ return (num2?gcd(num2,num1%num2):num1); }
ll lcm(ll num1,ll num2){ return 1LL*((num1*num2)/__gcd(num1,num2)); }
ll myceil(ll x,ll y){ return (x+y-1)/y;}
long long int my_log(ll n, long long int b){ll i = 1;long long int ans = 0;while (1){if (i > n){ans--;break;}if (i == n)break;i *= b;ans++;}return ans;}
//
ll countbit(ll num){ return 1LL*(__builtin_popcountll(num)); }
ll setbit(ll num, ll kk){ return 1LL*(num|(1LL<<kk)); }
ll unsetbit(ll num, ll kk){ return 1LL*(num&~(1LL<<kk)); }
ll invertbit(ll num, ll kk){ return 1LL*(num^(1LL<<kk)); }
bool kthbit(ll num, ll kk){ return num&(1LL<<kk); }
ll zerotrail(ll num){ return 1LL*(__builtin_ctzll(num)); }
ll zerobegin(ll num){ return 1LL*(__builtin_clzll(num)); }
//
ll prime[1000005]; 
void sieve(){ //spf
   forx(i,0,1000005) prime[i]=i; 
   for(ll p=2; 1LL*p*p<1000005; p++){ if(prime[p]==p) { for(ll i=1LL*p*p; i<1000005; i+=p) if(prime[i]==i) prime[i]=p; } } 
   return; 
} 
bool isPrime(ll pri){
   if(pri==1||pri==0) return 0;
   if(prime[pri]==pri) return 1;
   return 0;
}
vl alldiv(ll num){
   vl prDiv; for(ll i=1; 1LL*i*i<=num; i++){ if(num%i==0){ prDiv.pb(i); if(i!=(num/i)) prDiv.pb(num/i); } }
   sort(all(prDiv)); return prDiv;
}
vl prdiv(ll num){
   vl prDiv; while(num!=1){ prDiv.pb(prime[num]); ll prtemp=prime[num]; while(num%prtemp==0) num/=prtemp; }
   return prDiv;
}
//
const int MAX=1e5+1;
vector<vector<int>>adj(MAX);
// vector<int>eu(MAX),ev(MAX);
// bool used[MAX];
vvl dp(MAX, vector<ll>(2));
 
void dfs(int s=0,int p=-1){
   dp[s][0]=1,dp[s][1]=1;
   for(auto i : adj[s]){
      if(i!=p){
         dfs(i,s);
         dp[s][0]=(dp[s][0]%M*(dp[i][0]+dp[i][1])%M)%M;
         dp[s][1]=(dp[s][1]%M*dp[i][0]%M)%M;
      }
   }
}
 
void solve(){
   int n,m,x,y;
   cin>>n;
   forx(i,0,n-1) {
      cin>>x>>y;
      x--,y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   dfs();
   cout<<(dp[0][0]+dp[0][1])%M<<"\n";
   
   
}
//
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
 
   long long int x=1;
   //in(x);
   forx(u,0,x){
      //cout<<"Case #"<<h+1<<":"<<" ";
      solve();
 
   }
   return 0;
}
 