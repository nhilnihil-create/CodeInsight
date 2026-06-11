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
const int N = 2e5+30;
//https://codeforces.com/problemset/page/2?tags=1700-1700
 
 
void solve(){
   int H,W;
   cin>>H>>W;
   int dp[H+3][W+3];
   char c[H+1][W+1];
   for(int i=1;i<=H;i++){
     for(int j=1;j<=W;j++){
       cin>>c[i][j];
     }
   }
   memset(dp,0,sizeof(dp));
   dp[1][1]=1;
   for(int i=1;i<=H;i++){
     for(int j=1;j<=W;j++){
       if(c[i][j]=='.'){
        if(i-1>=1){
          dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
        }
        if(j-1>=1){
          dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
        }
       }
     }
   }
   cout<<dp[H][W]<<'\n';
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