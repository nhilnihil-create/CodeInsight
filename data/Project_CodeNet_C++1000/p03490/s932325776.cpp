#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>

using namespace std;
int dp[4005][16005]={};

int main(){
	long long n,k,l=0,odd=0,tmp,memo=0,x,y,len=0;
	bool key=true;
	queue<int>quex,quey;
	string str;
	cin>>str>>x>>y;
	while(str[memo]=='F')
	{
		x--;
		memo++;
	}
	for(int i=memo+1;i<=str.length();i++)
	{
		if((str[i]=='T'||i==str.length())&&key)
		{
			quey.push(len);
			y+=len;
			key=!key;
			len=0;
		}else if(key)
		{
			len++;
		}else if((str[i]=='T'||i==str.length())&&!key)
		{
			quex.push(len);
			x+=len;
			key=!key;
			len=0;
		}else if(!key)
		{
			len++;
		}
	}
	
	if(x<0||y<0)
	{
		cout<<"No";
		return 0;
	}
	tmp=1;
	dp[0][0]=1;
	while(!quex.empty())
	{
		for(int i=0;i<16002-quex.front();i++)
		{
			dp[tmp][i]=max(dp[tmp-1][i],dp[tmp][i]);
			dp[tmp][i+2*quex.front()]=max(dp[tmp-1][i],dp[tmp][i+2*quex.front()]);
		}
		tmp++;
		quex.pop();
	}
	//cout<<x<<" "<<dp[tmp][x];
	if(dp[tmp-1][x]==0)
	{
		cout<<"No"<<endl;
		return 0;
	}
	
	
	for(int i=0;i<=4000;i++)
	{
		for(int j=0;j<=16002;j++)
		{
			dp[i][j]=0;
		}
	}
	
	//cout<<"a";
	tmp=1;
	dp[0][0]=1;
	while(!quey.empty())
	{
		for(int i=0;i<16002-quey.front();i++)
		{
			dp[tmp][i]=max(dp[tmp-1][i],dp[tmp][i]);
			dp[tmp][i+2*quey.front()]=max(dp[tmp-1][i],dp[tmp][i+2*quey.front()]);
		}
		tmp++;
		quey.pop();
	}
	if(dp[tmp-1][y]==0)
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
}
