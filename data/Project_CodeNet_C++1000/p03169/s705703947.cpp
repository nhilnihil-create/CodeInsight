#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#define inputarr(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define prllarr(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" ";
#define pb push_back
#define ll long long
#define mod 1000000007
#define foi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define in(n) scanf("%lld",&n);
#define in2(x,y) scanf("%lld %lld",&(x),&(y));
#define in3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define out(n) printf("%lld\n",n);
#define out2(x,y) printf("%lld %lld\n",x,y);
#define test(t)  ll t; in(t);while(t--)
#define set(arr,n,s) for(ll i=0;i<n;i++){arr[i]=s;}


/*error-----
convert every int to long long eg-1LL
create array with proper analysis of problem constrain
check mod also
*/
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1){res=(res*x)%p;} y=y>>1;x=(x*x)%p;}return res;}
ll modInverse(ll a,ll p){return power(a,p-2,p);}//used with feemat little

ll gcd(ll x,ll y){if(x==0 || y==0){return max(y,x);}return gcd(y%x,x);}
ll gcdExtended(ll a,ll b,ll &x,ll &y){if(a==0){x=0;y=1;return b;}ll x1,y1;ll gcd = gcdExtended(b%a,a,x1,y1);x=y1-(b/a)*x1;y=x1;return gcd;}//o(log(b))
;
double dp[305][305][305];
ll cnt[4];
int main()
{
	ll n;
	in(n)
	for(ll i=0;i<n;i++){
		ll x;
		in(x);
		cnt[x]++;
	}
	//cout<<cnt[1]<<cnt[2]<<cnt[3]<<endl;
	
	for(ll sum=1;sum<=n;sum++){
		for(ll k=0;k<=sum;k++){
			for(ll j=0;j<=sum-k;j++){
				ll i=sum-j-k;
				dp[i][j][k]=n;
				if(k>0){
					dp[i][j][k]+=k*(dp[i][j+1][k-1]);
				}
				if(j>0){
					dp[i][j][k]+=j*(dp[i+1][j-1][k]);
				}
				if(i>0){
					dp[i][j][k]+=i*(dp[i-1][j][k]);
				}
				dp[i][j][k]/=(i+j+k);
			}
		}
	}	
	cout<<setprecision(10) <<dp[cnt[1]][cnt[2]][cnt[3]];


}




