#include <bits/stdc++.h>
using namespace std;

typedef __int128_t ll;

//typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

const int maxN = 2*1e5 + 10;
const int maxC = 1e6 + 10;
const int INF1 = 1e9;
const ll INF = 1LL<<62;

int n,m;
char s[maxN];
vector<int> path[maxN];
int tag[maxN];
int A[maxN];
int B[maxN];
queue<int> Q;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		path[u].push_back(v);
		path[v].push_back(u);
		if (s[v] == 'A' )
		{
			A[u] ++;
		}	
		else
		{
			B[u] ++;
		}
		if(s[u] == 'A')
		{
			A[v] ++;
		}
		else
		{
			B[v] ++;
		}
	} 
	for(int i=1;i<=n;i++)
	{
		if(A[i] == 0 || B[i] == 0)
		{
			Q.push(i);
			tag[i] = 1;
		}
	}
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for(auto y:path[x])
		{
			if(!tag[y])
			{
				if(s[x] == 'A')
				{
					A[y]--;
				}
				else
				{
					B[y]--;
				}
				if(A[y]==0 || B[y]==0)
				{
					tag[y] = 1;
					Q.push(y);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(tag[i] == 0)
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}