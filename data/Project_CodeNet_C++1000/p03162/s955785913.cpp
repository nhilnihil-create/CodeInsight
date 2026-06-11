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
   int n;
   cin>>n;
   int hap[n+3][5];
   for(int i=1;i<=n;i++){
     for(int j=1;j<=3;j++){
       cin>>hap[i][j];
     }
   }
   ll dp[n+3][4];
   memset(dp,0,sizeof(dp));
   for(int i=1;i<=n;i++){
     for(int j=1;j<=3;j++){
       for(int k=1;k<=3;k++){
         if(k!=j){
           dp[i][j] = max(dp[i][j],dp[i-1][k]+hap[i][k]);
         }
       }
     }
   }
   cout<<*max_element(dp[n]+1,dp[n]+3)<<'\n';
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