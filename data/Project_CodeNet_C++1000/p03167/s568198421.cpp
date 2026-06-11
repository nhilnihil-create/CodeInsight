#include<bits/stdc++.h>
using namespace std;
long long int dp[1001][1001];
long long int path(string s[],int i,int j,int h){
if(i>=s[0].size()||j>=h||s[j][i]=='#')return 0;
if(dp[j][i]!=-1)return dp[j][i];
if(i==(s[0].size()-1)&&j==h-1)return  1;
dp[j][i]=path(s,i+1,j,h)+path(s,i,j+1,h);
//cout<<dp[j][i]<<endl;
return dp[j][i]%(1000000000+7);
}



main(){
long long int h,w;
cin>>h>>w;
string s[h];
for(int i=0;i<h;i++)cin>>s[i];
memset(dp,-1,sizeof(dp));
cout<<path(s,0,0,h);


}
