/// Be Kind :)
#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Os")

/*				I take you to the candy shop								*/

/*				Ooooh ooh, it's me, myself and I
				Solo ride until I die, cause I got me for life				*/

/*				So I ball So hard, muh'fuckas wanna find me					*/
 
/*				Bitch, where you when I was walkin'?
				Now I run the game, got the whole world talkin'				*/
 
/*				Niggas been counting me out
				I'm counting my bullets, I'm loading my clips
				I'm writing down names, I'm making a list					*/
 
/*				You never liked us anyway, fuck your friendship, I meant it */
 
/*				The Chanel or Balenciaga, Louis and Vuitton
				She know I got Fendi, Prada when I hit Milan				*/
 
/*				I ran away, I don't think I'm coming back home				*/
 
#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll maxn=5e3+10, maxm=1e5+10, lg=17, mod=1e9+7, inf=1e18;

ll n,a,b,p[maxn],we[maxn],dp[maxn][maxn],ps[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++) cin>>p[i], we[p[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j==we[i]) dp[i][j]=ps[i-1][j-1];
			else dp[i][j]=ps[i-1][j]+(j<we[i] ? b:a);
			ps[i][j]=dp[i][j];
			if(j) ps[i][j]=min(ps[i][j],ps[i][j-1]);
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
	}
	cout<<ps[n][n];

	return 0;
}




