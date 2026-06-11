#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MP make_pair
#define MEM(i,j) memset(i,j,sizeof i)
#define Tie ios::sync_with_stdio(0),cin.tie(0)
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,a,b,toa[200001],tob[200001],tmp,cnt;
string s;
vector<int> v[200001];
queue<int> q;
bitset<200001> u;

int main()
{
	cin>>n>>m>>s;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b,a--,b--;
		v[a].push_back(b),v[b].push_back(a);
		if(s[a]=='A')
			toa[b]++;
		else tob[b]++;
		if(s[b]=='A')
			toa[a]++;
		else tob[a]++;
	}
	for(int i=0;i<n;i++)
		if(toa[i]==0||tob[i]==0)
			q.push(i),cnt++,u[i]=1;
	while(!q.empty())
	{
		tmp=q.front(),q.pop();
		for(int i:v[tmp])
		{
			if(s[tmp]=='A')
				toa[i]--;
			else
				tob[i]--;
			if(!u[i]&&(toa[i]==0||tob[i]==0))
				q.push(i),cnt++,u[i]=1;
		}
	}
	if(cnt==n)cout << "No\n";
	else cout << "Yes\n";
}