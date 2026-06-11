#include <bits/stdc++.h>
using namespace std;
int deg[200005][2], vis[200005];
vector<int> v[200005], q;
int main(){
	int n,m; string s;
	cin>>n>>m>>s;
	s = '#' + s;
	for(int i=m,x,y;i--;){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		++deg[x][s[y]-'A'], ++deg[y][s[x]-'A'];
	}
	for(int i=1;i<=n;++i)
		if(!deg[i][0] || !deg[i][1]){
			q.push_back(i);
			vis[i] = 1;
		}
	for(int j=0;j<q.size();++j)
		for(auto i:v[q[j]]) if(!--deg[i][s[q[j]]-'A'] && !vis[i]){
			q.push_back(i);
			vis[i] = 1;
		}
	cout<<(q.size()<n?"Yes":"No");
}