#include<bits/stdc++.h>
#define ll 	 long long
#define pb push_back
#define mp make_pair
using namespace std;

#define mmm    ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{

mmm;

    string s,t;
    cin>>s>>t;
    s=' '+s;
    t=' '+t;
    int n=s.length(),m=t.length();
    int dp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            if(s[i]==t[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n-1,j=m-1;
    string ans="";
    while(i>0 && j>0){
        if(s[i]==t[j]){
            ans=s[i]+ans;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<ans<<endl;

     return 0;
}