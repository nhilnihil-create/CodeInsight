#include<bits/stdc++.h>
using namespace std;

int n,m;
map<string,int>	c;
string a[20];
string dp[20005];

string mx(string i,string j)
{
	if(i.size()==j.size())
	{
		if(i>=j)	return i;
		else j;
	}
	if(i.size()>j.size())	return i;
	else return j;
}



int main()
{
	cin>>n>>m;
	c["1"]=2,c["2"]=5,c["3"]=5,c["4"]=4,c["5"]=5,c["6"]=6,c["7"]=3,c["8"]=7,c["9"]=6;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			string r=a[j];
			if(i<c[r])	continue;
			if(dp[i-c[r]]=="" && i-c[r]!=0)	continue;
			dp[i]=mx(dp[i],r+dp[i-c[r]]);
		}
	}
	cout<<dp[n]<<endl;
	
	
}





