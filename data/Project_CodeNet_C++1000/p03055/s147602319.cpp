#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
const int N=2e5+10;

int gi() {
	int x=0,o=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int n,mx,p;
vi E[N];
bool win[N];

void dfs(int u,int ff,int dis) {
	if(dis>mx) mx=dis,p=u;
	for(auto v:E[u]) if(v!=ff) dfs(v,u,dis+1);
}

int main() {
	cin>>n;
	for(int i=1,u,v;i<n;i++) u=gi(),v=gi(),E[u].pb(v),E[v].pb(u);
	dfs(1,0,0);mx=0;dfs(p,0,0);
	win[0]=1;
	for(int i=2;i<=mx;i++) {
		if(!win[i-1]||!win[i-2]) win[i]=1;
	}
	puts(win[mx]?"First":"Second");
	return 0;
}
