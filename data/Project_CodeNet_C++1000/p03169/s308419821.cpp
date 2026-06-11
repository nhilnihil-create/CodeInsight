#include<bits/stdc++.h>
#define ll          long long int
#define lld          long double
#define pb          push_back
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define vec         vector<ll>
#define all(a)     (a).begin(),(a).end()
#define F           first
#define S           second
#define mod         1000000007
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define xxx         exit(0);
#define pit         pair<ll,ll>::iterator
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
ll xo(ll x, ll y) 
{ 
   return (x | y) & (~x | ~y); 
}  
ll bin_Expo(ll x,ll n)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return bin_Expo(x*x,n/2);
    else                             //n is odd
        return x*bin_Expo(x*x,(n-1)/2);
}
ll mod_Expo(ll x,ll n,ll M)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return mod_Expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*mod_Expo((x*x)%M,(n-1)/2,M))%M;

}
bool prime_check(ll x)
{
    bool prime = (x >= 2);
    for (ll i = 2; i * i <= x; i++) 
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
}
ll logg(ll base,ll x) {
    return (ll)(log(x) / log(base));
}
lld dp[303][303][303]; ll n;
lld E(ll a, ll b, ll c)
{
	if(a<0 || b<0 || c<0) return 0;
	if(dp[a][b][c]!=-1.00) return dp[a][b][c];
	lld ans=((n*1.0)/((a+b+c)*1.00));
	if(a>0) ans+=((a*1.0)/((a+b+c)*1.00))*E(a-1,b,c);
	if(b>0) ans+=((b*1.0)/((a+b+c)*1.00))*E(a+1,b-1,c);
	if(c>0) ans+=((c*1.0)/((a+b+c)*1.00))*E(a,b+1,c-1);
	return dp[a][b][c]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
    while(TESTS--)
    {
    	ll k,i,j,l,m,h,w,val,d,a,b,c;
    	cin>>n;
    	a=0; b=0; c=0;
    	rep(i,0,n)
		{
    		cin>>h;
    		if(h==1) a++;
    		else if(h==2) b++;
    		else c++;
		}
		cout<<fixed<<setprecision(15);
		repi(i,0,300){
			repi(j,0,300){
				repi(k,0,300) dp[i][j][k]=-1.00;
			}
		}
		dp[0][0][0]=0.00;
    	cout<<E(a,b,c);
	}
	return 0;
}