#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int dp[2][8001];
int main() {
	
	int t;
	//cin>>t;
	t=1;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int x,y;
	    cin>>x>>y;
	    int sumx=0, sumy=0;
	    vector<int> v[2];
	    
	    int cur = 0;
	    int len=0;
	    
	    int j=0,cnt=0;
	    while(j<s.length() && s[j]!='T'){
	        cnt++;
	        j++;
	    }
	    for(int i=j;i<s.length();i++){
	        if(s[i]=='T'){
	            if(len>0)
	                v[cur].push_back(len);
	            cur^=1;
	            len=0;
	        }
	        else{
	            len++;
	        }
	    }
	    if(len>0){
	        v[cur].push_back(len);
	    }
	    dp[0][0]=dp[1][0]=1;
	    for(int i=0;i<v[0].size();i++){
	        sumx+=v[0][i];
	        for(int j=8000;j>=v[0][i];j--){
	            if(dp[0][j-v[0][i]]){
	                dp[0][j]=1;
	            }
	        }
	    }
	    for(int i=0;i<v[1].size();i++){
	        sumy+=v[1][i];
	        for(int j=8000;j>=v[1][i];j--){
	            if(dp[1][j-v[1][i]]){
	                dp[1][j]=1;
	            }
	        }
	    }
	    bool fx=0,fy=0;
	    for(int i=0;i<=8000;i++){
	        if(dp[0][i] && ((2*i-sumx) == (x-cnt)))
	            fx=1;
	        if(dp[1][i] && ((2*i-sumy) == y))
	            fy=1;
	    }
	    if(fx && fy)
	        cout<<"Yes\n";
        else
            cout<<"No\n";
	}
	
	return 0;
}
