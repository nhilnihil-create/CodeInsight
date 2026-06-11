#include<bits/stdc++.h>
using namespace std;

const int size=100010;
int n,m;
int used[size];
int d[size];
bool flag=false;
struct edge//from left to right
{
 	int to,val;
 	edge(int to=0,int val=0):to(to),val(val) {}
 };

vector<edge> V[size];

void dfs(int from,int to,int len)
{
 	if(used[to])
 		if(d[from]+len!=d[to])
 		{
		 	cout<<"No"<<endl;
		 	exit(0);
			}
		else return;
		
	used[to]=1;
	d[to]=d[from]+len;
	for(int i=0;i<V[to].size();i++)
	{
		int nto=V[to][i].to;
		dfs(to,nto,V[to][i].val);
		}
	} 

int main()
{
	cin>>n>>m;
	if(m==0)
	{
		cout<<"Yes"<<endl;
		return 0;
		}	
	
	for(int i=0;i<m;i++)
	{
		int L,R,len;
		cin>>L>>R>>len;
		V[L].push_back(edge(R,len));
		V[R].push_back(edge(L,-len));
		}
	for(int i=1;i<=n;i++)
		if(!used[i])
			dfs(i,i,0);
	cout<<"Yes"<<endl;		
 	return 0;
 }