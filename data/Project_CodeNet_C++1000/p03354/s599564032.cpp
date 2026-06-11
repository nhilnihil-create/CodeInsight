#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
typedef set <int> si;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 100005
#define mp make_pair
#define int ll
int N,M,A[maxn];

int p[maxn];
int ans = 0;

int fL(int x){
	if (p[x] == x) return x;
	return p[x] = fL(p[x]);
}

void join(int a,int b){
	p[fL(a)] = fL(b);
}

vi B[maxn];
vi C[maxn];
bool vis[maxn];
int32_t main(){
	fast;
	cin>>N>>M;
	
	FOR(i,1,N) p[i] = i;
	
	FOR(i,1,N) cin>>A[i];
	FOR(i,0,M-1){
		int a,b;
		cin>>a>>b;
		join(a,b);
	}


	FOR(i,1,N){
		int a = fL(i);
		B[a].pb(i);
		C[a].pb(A[i]);
	}
	
	FOR(i,1,N){
		if (!vis[fL(i)]){
			sort(all(B[fL(i)]));
			sort(all(C[fL(i)]));
			vis[fL(i)] = 1;
		}
	}
	mem(vis,0);
	int ans = 0;
	FOR(i,1,N){
		int a = fL(i);
		if (!vis[a]){
			aFOR(j,C[a]){
				//cout<<j<<' ';
				auto it = lower_bound(all(B[a]),j);
				if (it != B[a].end() && *it == j) ans++;
			}
			vis[a] = 1;
		}
	}
	cout<<ans;
}
