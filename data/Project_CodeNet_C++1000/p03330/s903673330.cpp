#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
   int N,C;
   cin >> N >> C;
   vector<vector<ll>>D(C,vector<ll>(C));
   rep(i,C)rep(j,C)cin >> D[i][j];
   vector<vector<ll>>cos(3,vector<ll>(C,0));
   rep(i,N)rep(j,N){
       int c;cin >> c;c--;
       rep(k,C){
           cos[(i+j)%3][k]+=D[c][k];
       }
   }
   ll ans=(ll)(1e15);
   rep(i,C)rep(j,C)rep(k,C){
       if(i==j||j==k||k==i){continue;}
       ans=min(ans,cos[0][i]+cos[1][j]+cos[2][k]);
   }
   printf("%d\n",ans);
   return 0;
}