#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int mod=int(1e9)+7;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string s,t;
    cin>>s;
    cin>>t;
    int n=s.size();
    int m=t.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else{
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    int i=n,j=m;
    vector<char> v;
    while(i>=1&&j>=1){
        if(s[i-1]==t[j-1]){
            v.push_back(s[i-1]);
            i--;
            j--;
        }
        else{
            int g=max(dp[i-1][j],dp[i][j-1]);
            if(g==dp[i-1][j]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(v.begin(),v.end());
    for(auto h:v){
        cout<<h;
    }
    cout<<"\n";

}