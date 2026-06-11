#include<iostream>
using namespace std;
#include<vector>
#include<cmath>
#define int long long int
#define inf 2001
int memo[1001][1001];
int function(char mat[1001][1001],int i,int j,int n,int m,bool visited[1001][1001])
{
	if(i<0||i>=n||j<0||j>=m)
	    return inf;
	if(visited[i][j]==true)
	   return inf;
	if(mat[i][j]=='#')
	   return 0;
	else
	{
		visited[i][j]=true;
		int x=1+function(mat,i+1,j,n,m,visited);
		int y=1+function(mat,i-1,j,n,m,visited);
		int z=1+function(mat,i,j-1,n,m,visited);
		int t=1+function(mat,i,j+1,n,m,visited);
		memo[i][j]=min(memo[i][j],min(min(x,y),min(z,t)));
		return memo[i][j];
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
     int w=0;
     string str;
     cin>>str;
     int j;
     for(j=0;str[j]!='\0';j++)
     {
		 if(str[j]=='o')
		     w++;
	 }
	 w+=(15-str.size());
	 cout<<(w>=8?"YES":"NO")<<endl;
}
