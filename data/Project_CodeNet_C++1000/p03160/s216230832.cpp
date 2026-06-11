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
   int a[n+3];
   int dp[n+3];
   for(int i=1;i<=n;i++){
     dp[i] = 1e9;
   }
   for(int i=1;i<=n;i++){
     cin>>a[i];
   }
   dp[1]  = 0;
   for(int i=1;i<=n;i++){
     if(i-1>=1){
       dp[i] = min(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
     }
     if(i-2>=1){
       dp[i] = min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
     }
   }
   cout<<dp[n]<<'\n';
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