#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
int n;
// double dfs(int a, int b, int c){
//     if(a+b+c == 0)
//     return 0.0;
//     if(dp[a][b][c] > -0.5)
//     return dp[a][b][c];
//     double ks = (double)n/ (a+b+c);
//     double ret=0;
//     if(a){
//         ret += (dfs(a-1,b,c) + ks)*(a/(a+b+c));
//     }
//     if(b){
//         ret += (dfs(a+1,b-1,c) + ks)*(b/(a+b+c));
//     }
//     if(c){
//         ret += (dfs(a,b+1,c-1) + ks)*(c/(a+b+c));
//     }
//     return dp[a][b][c]=ret;
// }
double rec(int i, int j, int k){
  if(!i && !j && !k)return 0.0;
  if(dp[i][j][k]>0.0)return dp[i][j][k];
 
  double sum = i+j+k;
  double ret = n/sum;
  if(i>0)ret += (double)(i/sum) * rec(i-1, j, k);
  if(j>0)ret += (double)(j/sum) * rec(i+1, j-1, k);
  if(k>0)ret += (double)(k/sum) * rec(i, j+1, k-1);
 
  return dp[i][j][k]=ret;
}


int main() {
    //memset(dp, -1, sizeof(dp));
    for(int i=0;i<301;i++){
        for(int j=0;j<301;j++){
            for(int k=0;k<301;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    int st[4];
     memset(st, 0, sizeof(st));
    
     cin>>n;
     for(int i=0;i<n;i++){
         int t;
         cin>>t;
         st[t]++;
     }
    // cout<<dfs(st[1],st[2],st[3]);
    // cout<<setprecesion(12)<<dfs(st[1],st[2],st[3]);
    cout<<fixed<<setprecision(12)<<rec(st[1], st[2], st[3])<<endl;
     
	return 0;
}