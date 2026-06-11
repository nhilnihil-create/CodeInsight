#include <iostream>
#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
void cp(string s1,string s2,int k){
    int l=s2.length();
int dp[k+1][l+1];
for(int i=0;i<=k;i++)
dp[i][0]=0;
for(int i=0;i<=l;i++)
dp[0][i]=0;
for(int i=1;i<=k;i++){
    for(int j=1;j<=l;j++)
    {
        if(s1[i-1]==s2[j-1])
        dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }

}
int index= dp[k][l];
char lcs[index+1];
lcs[index]='\0';
int i=k,j=l;
while(i>0 && j>0){
    if(s1[i-1]==s2[j-1]){
        lcs[index-1]=s1[i-1];
        i--;j--;index--;

    }
    else if(dp[i-1][j]>dp[i][j-1])
    i--;
    else
    j--;
}
cout<<lcs;
    }
    

int main() {
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int k=s1.length();

    cp(s1,s2,k);
}
