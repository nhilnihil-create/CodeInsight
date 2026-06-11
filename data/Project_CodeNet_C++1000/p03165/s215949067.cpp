#include<bits/stdc++.h>
using namespace std;
char maxLenString(int a,int b){
    return (a>b?'|':'-');
}
string solve(string a,string b){
    int n=a.size();
    int m=b.size();
    vector<vector<char>> chars(n+1,vector<char>(m+1,':'));
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }else if(a[i-1]==b[j-1]){
                    chars[i][j]='d';
                    dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                chars[i][j]=maxLenString(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    int i=n;
    int j=m;
    while(i>=0 && j>=0){
        if(chars[i][j]=='d'){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }else if(chars[i][j]=='-'){
            j--;
        }else{
            i--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
	string a,b;
    cin>>a>>b;
    cout<<solve(a,b);
	return 0;
	
}
