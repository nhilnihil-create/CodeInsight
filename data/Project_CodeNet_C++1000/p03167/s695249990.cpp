#include<bits/stdc++.h>
using namespace std;
#define NitroBoost \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);
#define ll long long
#define fori(i,l,n) for(int i=l;i<n;i++)
#define ford(i,n,l) for(int i=n;i>l;i--)
#define All(i,x) for(auto i=x.begin();i!=x.end();++i)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) (((a)*(b))/gcd((a),(b)))
#define test int t;cin>>t;while(t--)
#define pb(i) push_back(i)
#define watch(x) cout<<(#x)<<"="<<(x)<<"\n"
#define str(n) to_string(n)
#define fi first
#define sec second
#define prec(n) fixed<<setprecision(n)
#define mp make_pair
const double pi=3.141592653589793;
const int MOD=1e9+7;
ll power(ll x, ll y, ll m) 
{
     ll res = 1;x %= m;
    while (y > 0) {
        if (y & 1)
        res = (res*x) % m;
        y>>=1;
        x = (x*x) % m;
    }
    return res%m;
}
ll look[1000][1000];
ll dp(char a[][1000],int r, int c){
	if(r==1 && c==1)
	return 1;
	if(look[r-1][c-1]!=-1)
	return look[r-1][c-1]%MOD;
	if(a[r-1][c-1]=='#')
	return 0;
	if(r==1)
	return look[r-1][c-1]=dp(a,r,c-1)%MOD;
	if(c==1)
	return look[r-1][c-1]=dp(a,r-1,c)%MOD;
	return look[r-1][c-1]=(dp(a,r-1,c)%MOD+dp(a,r,c-1)%MOD)%MOD;
}
void solve(){
    int h,w;	
	cin>>h>>w;
	char a[h][1000];
	fori(i,0,h){
		fori(j,0,w)
		cin>>a[i][j];
	}
	fori(i,0,1000)
	{
		fori(j,0,1000)
		look[i][j]=-1;
	}
	cout<<dp(a,h,w)<<"\n";
}
int main(){  
    NitroBoost
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    //test
    {
        solve();
    }
    return 0;
}