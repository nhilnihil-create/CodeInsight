#include <iostream>
#include <vector>
using namespace std;
int main(){
	string s, t;
  	cin>>s>>t;
  	vector<vector<int>> dp(s.size(), vector<int>(t.size()));
    vector<vector<pair<int,int>>> bt(s.size(), vector<pair<int, int>>(t.size(), {-1,-1}));
	for(int i =0;i<s.size();i++){
    	for(int j=0;j<t.size();j++){
        	if(s[i]==t[j]){
           		if(i>0 && j>0){
               		dp[i][j] = dp[i-1][j-1] + 1;
                	bt[i][j] = {i-1, j-1};
                }
            	else{                 
                  dp[i][j] = 1;
                  bt[i][j] = {i-1, j-1};
                }
            }else{
              	if(i>0 && dp[i-1][j]> dp[i][j] ){
                 	dp[i][j] =  dp[i-1][j];
                	bt[i][j] = {i-1,j};
                }
              	if(j>0 && dp[i][j-1]>dp[i][j]){
                	dp[i][j] = dp[i][j-1];
                	bt[i][j] = {i, j-1};
                }
            }
        }
    }
      
    string ans;
    int i = s.size()-1;
    int j = t.size()-1;
   	while(i>=0 && j>=0){
      if(s[i]==t[j]){
        ans+=s[i];
      } 
      int tmp = i;
      i = bt[i][j].first;
      j = bt[tmp][j].second;

    } 
	reverse(ans.begin(), ans.end());
  	cout<<ans<<endl;

}