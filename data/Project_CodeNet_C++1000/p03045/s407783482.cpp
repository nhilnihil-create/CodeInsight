#include<bits/stdc++.h>
using namespace std;

#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
vector<int> v[100005];
int vis[100005];
void dfs(int r){
	vis[r]=1;
	for(int x: v[r]){
		if(vis[x]==0)
			dfs(x);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b,q;
		cin>>a>>b>>q;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cou=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			cou++;
			dfs(i);
		}
	}
	cout<<cou<<endl;
	return 0;
}