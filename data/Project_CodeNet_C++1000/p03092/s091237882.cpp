#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end

ll dp[5010][10101];

int main(){
   int n,a,b; cin>>n>>a>>b;
   vector<int> p(n); rep(i,0,n)cin>>p[i],p[i]--;
   vector<int> rev(n); rep(i,0,n)rev[p[i]]=i*2+1;
   rep(i,0,n+1)rep(j,0,2*n+1)dp[i][j]=INF;
   rep(j,0,2*n+1)dp[0][j]=0;
   rep(i,0,n){
      rep(j,0,2*n+1){
         int add;
         if(j==rev[i])add=0;
         if(j>rev[i])add=a;
         if(j<rev[i])add=b;
         chmin(dp[i+1][j],dp[i][j]+add);
      }
      rep(j,0,2*n)chmin(dp[i+1][j+1],dp[i+1][j]);
   }
   cout<<dp[n][2*n]<<endl;
   return 0;
}