//here H and W is less so no need of recursion style dp...do the dp tabulation
#include<bits/stdc++.h>
#define N 1000000007
using namespace std;

int dp[10001][10001];  //global has default zero
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>v;
    v.assign(h,vector<char>(w,'0'));
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)cin>>v[i][j];
                             //here dp is for number of ways so no ways means dp is 0
    //these extra row and column used in states of first row and column
                                        //or use condition if we dont want to use these extra row and column
     dp[1][1]=1;
     for(int i=1;i<=h;i++){
         for(int j=1;j<=w;j++){
             if(i==1&&j==1)continue;
             if(v[i-1][j-1]=='#')dp[i][j]=0;        //it makes our condition satisy as we make reaching ways to # 0 s further ways from here also 0
             else
             dp[i][j]=(dp[i-1][j]%N+dp[i][j-1]%N)%N;
         }
     }
     cout<<dp[h][w]<<endl;
     return 0;                               
}
