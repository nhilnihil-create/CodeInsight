#include<iostream>
using namespace std;
#include<vector>
#include<cmath>
#define int long long int
#define mod 1000000007
#define inf 20001
int function(char mat[101][101],int x1,int y1,int x2,int y2,int n,int m,bool visited[101][101])
{
	if(x1<0||x1>n||y1<0||y1>m)
	    return inf;
	if(x1==x2&&y1==y2)
	{
		return 0;
	}
	if(visited[x1][y1])
	    return inf;
	else
	{
		visited[x1][y1]=true;
		int answer=0;
		if(mat[x1][y1]=='1')
		  answer++;
	    int a=answer+function(mat,x1+1,y1,x2,y2,n,m,visited);
	    int b=answer+function(mat,x1-1,y1,x2,y2,n,m,visited);
	    int c=answer+function(mat,x1,y1+1,x2,y2,n,m,visited);
	    int d=answer+function(mat,x1,y1-1,x2,y2,n,m,visited);
	    return min(min(a,b),min(c,d));
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int x,y;
    cin>>x>>y;
    if(2*c<a+b)
    {
		int answer=min(x,y)*2*c;
		int p=min(x,y);
		x-=p;
		y-=p;
		if(x!=0)
		{
			int u=a*x;
			int v=2*c*x;
			answer+=min(u,v);
		}
		else if(y!=0)
		{
			int u=b*y;
			int v=2*c*y;
			answer+=min(u,v);
		}
		cout<<answer<<endl;
	}
	else
	{
		int answer=a*x+b*y;
		cout<<answer<<endl;
	}
    
}
