#include<bits/stdc++.h>
using namespace std;
int M=310;
double dp[310][310][310];
int n;

double dfs(int a, int b, int c){
      if((a+b+c)==0)return 0.;

      if(dp[a][b][c]!=-1)return dp[a][b][c];

      double ks=((double)n/(a+b+c));
      double res=0.0;

      if(a){
            res+=((dfs(a-1, b, c)+ks)*a/(a+b+c));
      }
      if(b){
            res+=((dfs(a+1, b-1, c)+ks)*b/(a+b+c));
      }
      if(c){
            res+=((dfs(a, b+1, c-1)+ks)*c/(a+b+c));
      }
      dp[a][b][c]=res;
      return res;
}
int main(){
      cin>>n; 
      int arr[4];
      arr[0]=arr[1]=arr[2]=arr[3]=0;
      for(int i=0; i<=n; i++)for(int j=0; j<=n; j++)for(int k=0; k<=n; k++)dp[i][j][k]=-1;

      for(int i=0; i<n; i++){
            int x;
            cin>>x;
            arr[x]++;
      }
      cout<<fixed<<setprecision(10)<<dfs(arr[1], arr[2], arr[3]);
}