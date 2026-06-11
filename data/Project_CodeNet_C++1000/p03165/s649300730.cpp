#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    map<char,char> trk;
    int n,m;
    n=a.size();
    m=b.size();
    char ch='.';
    int dp[n+1][m+1];
  
    
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            
                if(i==n || j==m) dp[i][j]=0;
            else if(a[i]==b[j]){
                dp[i][j]=dp[i+1][j+1]+1;
              
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        
        }
    }
    vector<char> cc;
    int i=0,j=0;
    while(dp[i][j]!=0){
        int x;
            x=max(dp[i+1][j],dp[i][j+1]);
            if(dp[i][j]!=x){
                 cc.push_back(a[i]);
                 i++;j++;
            }
            else{
                if(dp[i+1][j]==dp[i][j]) i++;
                else j++;
            }
    }
            
        
    for(int i=0;i<cc.size();i++) cout << cc[i];
    cout << endl;
    
   
   // cout << dp[0][0] << endl;
}