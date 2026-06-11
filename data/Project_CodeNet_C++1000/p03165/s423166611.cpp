
#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
    string s1,s2;
    cin>>s1>>s2;
    ll n1,n2;
    n1=s1.size();
    n2=s2.size();
    vector<vector<ll> >dp(n1+1,vector<ll>(n2+1,0));
    for(ll i = 1 ; i < n1+1 ; i++ ){
        for(ll j = 1 ; j < n2+1 ; j++ ){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    ll i = n1;
    ll j  = n2;
   
    while(i>0 && j >0 ){
               if( s1[i-1]==s2[j-1]){
                   ans+=s1[i-1];
                   i--;
                   j--;
               }
               else if(dp[i-1][j]>dp[i][j-1]){
                   i--;
               }
               else{
                   j--;
           }
       }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
