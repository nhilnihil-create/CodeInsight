#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 200500000000000
#define MOD 10007
#define N 100005
#define M 1000005
#define LOG 18
#define KOK 4000000
using namespace std;

int n,m,a,b,c;
int pos[N],vis[N];
vector<ii> v[N];

void fail() {

	printf("No");

	exit(0);

}

void dfs(int node)  {

	vis[node]=1;

	for(ii i:v[node]) {

		if(!vis[i.st]) {

			pos[i.st]=pos[node]+i.nd;

			dfs(i.st);

		}

	}

}

int main() {

	//freopen("input.txt","r",stdin);

	scanf("%d %d",&n,&m);

	for(int i=1;i<=m;i++) {

		scanf("%d %d %d",&a,&b,&c);

		v[b].pb({a,c});
		v[a].pb({b,-c});

	}

	for(int i=1;i<=n;i++) {

		if(!vis[i]) {

			dfs(i);

		}

	}

	for(int i=1;i<=n;i++) {

		for(ii go:v[i]) {

			if(pos[i]+go.nd!=pos[go.st]) fail();

		}

	}

	printf("Yes");

}

