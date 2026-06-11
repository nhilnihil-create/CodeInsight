#include <bits/stdc++.h>
 
#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( int i = a; i >= b ; i--)
#define rep(i,a,b,k) for(int i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( int i = a; i >= b ; i-= k)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;

const int MAX= 3e3 +3;

ll dp[MAX][MAX],mod=1e9+7;
int main(){
	fastio;
	ll n;
	string s;
	cin>>n>>s;
	dp[1][1]=1;
	f(i,2,n+1){
		if(s[i-2]=='<'){
			f(j,2,i+1) 
				dp[j][i]=dp[j-1][i-1]+dp[j-1][i];
			
		}
		else{
			af(j,i-1,1) dp[j][i]=dp[j][i-1]+dp[j+1][i];
		}	
		f(j,1,n+1) dp[j][i]=dp[j][i]%mod;
	}
	ll ans=0;
	f(i,1,n+1) ans+=dp[i][n];
	cout<<ans%mod<<endl;

    return 0;

}