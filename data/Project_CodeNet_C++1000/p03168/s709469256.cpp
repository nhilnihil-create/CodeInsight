#include <bits/stdc++.h>
using namespace std;
 
#define MOD (1000000007)
#define f first
#define s second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
typedef long long int ll;
#define ld long double
const int N = 3003;
//https://codeforces.com/problemset/page/2?tags=1700-1700
ld ans=0;
ld dp[N][N];
 
void solve(){
   int n;
   cin>>n;
   ld prob[n+3];
   for(int i=1;i<=n;i++){
     cin>>prob[i];
   }
   //ld dp[n+3][n+3];
   dp[0][0]=1;
   for(int i=1;i<=n;i++){
     for(int j=0;j<=i-1;j++){
       dp[i][j+1] += dp[i-1][j]*prob[i];
       dp[i][j] += dp[i-1][j]*(1-prob[i]);
     }
   }
   ld ans=0;
   for(int i=n/2+1;i<=n;i++){
     ans+=dp[n][i];
   }
   cout<<fixed<<setprecision(12)<<ans<<'\n';
}
 
 
int main(){
 	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int T;
  //cin >> T;
  //cout<<prs.size()<<'\n';
	 T = 1;
  //visited[1]=1;
	while(T--){
		solve();
	}
}