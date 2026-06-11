#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i=1;i<=n;i++)
#define REP(i,a,b) for (int i=a;i<=b;i++)
 
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define mp make_pair
#define sz(x) ((int)(x).size())
 
typedef long long ll;

const int inf=0x3f3f3f3f;
const ll linf=1e18;
const int N=200000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
vector<int> v[N];
int fa[N];
ll D[N];
int sz[N];
struct node {
	int id;
	ll v;
} a[N];
bool used[N];
bool cmp(node x,node y) {
	return x.v<y.v;
}
int F(int x) {
	return (fa[x]==x)?x:(fa[x]=F(fa[x]));
}
int find(ll x) {
	int l=1,r=n;
	int mid;
	while (l<=r) {
		mid=(l+r)>>1;
		if (a[mid].v<x) {
			l=mid+1;
		} else if (a[mid].v>x) {
			r=mid-1;
		} else return a[mid].id;
	}
	return 0;
}
void dfs(int x,int s,int d,int f) {
	D[s]+=d;
	int t;
	for (int i=0;i<(int)v[x].size();i++) {
		t=v[x][i];
		if (t!=f) {
			dfs(t,s,d+1,x);
		}
	}
}
bool check() {
	dfs(a[1].id,a[1].id,0,0);
	if (D[a[1].id]!=a[1].v) return 0;
	return 1;
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	scanf("%d",&n);
	int x,y;
	FOR(i,n) {
		scanf("%lld",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	FOR(i,n) sz[i]=1,fa[i]=i;
	ll t;
	for (int i=n;i>=2;i--) {
		x=a[i].id;
		t=a[i].v-n+2*sz[x];
		//cout<<x<<" "<<t<<endl;
		y=find(t);
		if (F(x)==F(y)||used[y]||y==0) {
			cout<<-1<<endl;
			return 0;
		}
		v[x].pb(y);
		v[y].pb(x);
		sz[y]+=sz[x];
		fa[F(x)]=F(y);
		used[x]=1;
		// used[x]=1表示x的所有儿子都已经找到了，之后如果还有点想插入x当儿子就是无解的 
	}
	if (!check()) {
		cout<<-1<<endl;
		return 0;
	}
	FOR(i,n) {
		for (int j=0;j<(int)v[i].size();j++) {
			y=v[i][j];
			if (i<y) {
				printf("%d %d\n",i,y);
			}
		}
	}
	return 0;
}