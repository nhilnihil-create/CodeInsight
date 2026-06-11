#include <bits/stdc++.h>
using namespace std;
string s,t;
int s_len, t_len;
int dp[3001][3001];
int lcs(int i, int j){
    if(i>= s_len || j>=t_len ){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
if(s[i]==t[j]){
   return dp[i][j]=1+lcs(i+1, j+1);
}
     int op1=lcs(i+1,j);
     int op2=lcs(i,j+1);
return dp[i][j]=max(op1,op2);
}
string solve(){
    memset(dp,-1,sizeof dp);
    s_len= s.length();
    t_len= t.length();
    string ans;
   int len=lcs(0,0);
       
       // GET LCS
       int i=0, j=0;
       while(len>0){
           if(s[i]==t[j]){
               ans.push_back(s[i]);
               i++;
               j++;
               len--;
           }
           else{
             if(dp[i+1][j] > dp[i][j+1]){
             i++;}
             else{
             j++; 
             }  

           }
       }

return ans;
}

int32_t main() {
      cin>>s>>t;
     // cout<<s<<" "<<t;
    cout<<solve();
    return 0;
}
