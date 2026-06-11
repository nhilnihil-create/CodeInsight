#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	
	string a,b;
	cin>>a;
	cin>>b;
	int n=a.size(),m=b.size();
	int dp[n+1][m+1];
	
	for(int i=0;i<=n;i++)
	{
	    for(int j=0;j<=m;j++)
	    {
	        if(i==0||j==0)
	            dp[i][j]=0;
	        else if(a[i-1]==b[j-1]&&a[i-1]!=' ')
    	        dp[i][j]= dp[i-1][j-1]+1;
    	    else
    	        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	    }
	}
	string ans="";
	int x=n,y=m;
  	while(x!=0 && y!=0){
  		if(dp[x-1][y]==dp[x][y]){
  			--x;
  		}
  		else if(dp[x][y-1]==dp[x][y]){
  			--y;
  		}
  		else{
  			ans=b[y-1]+ans;
          	x--;
          	y--;
  		}
  	}
// 	reverse(s.begin(),s.end());
	cout<<ans<<endl;
	
	
	return 0;
}