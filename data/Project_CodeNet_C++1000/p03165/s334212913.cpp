#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int sl=s.length(),tl=t.length();
    int dp[sl+1][tl+1];
    for(int i=0;i<=s.length();i++){
    	for(int j=0;j<=t.length();j++){
    		dp[i][j]=0;
    	}
    }
    for(int i=0;i<s.length();i++){
    	for(int j=0;j<t.length();j++){
    		if(s[i]==t[j]){
    			dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
    		}
    		else{
    			int tmp=max(dp[i+1][j],dp[i][j+1]);
    			dp[i+1][j+1] = max(dp[i+1][j+1],tmp);
    		}
    		dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
    		dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
    	}
    }
    /*for(int i=0;i<=s.length();i++){
    	for(int j=0;j<=t.length();j++){
    		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    	}
    }*/
    //cout<<dp[s.length()][t.length()]<<endl;
    int index = dp[s.length()][t.length()];
    char lcs[index+1];
    lcs[index]='\0';
    int i=sl,j=tl;
    while(i>0 && j>0){
    	if(s[i-1]==t[j-1]){
    		lcs[index-1]=s[i-1];
    		i--;j--;index--;
    	}
    	else if (dp[i-1][j] > dp[i][j-1]){
         	i--; 
    	}
		else{
		 	j--; 
		}
    }
    cout<<lcs;
    return 0;
}