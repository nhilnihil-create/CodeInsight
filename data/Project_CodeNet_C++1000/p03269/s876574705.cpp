#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
typedef pair <pi,ll> pii;
typedef vector <pii> vpii;
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

int L;
vpii edges;

int msb;

int main(){
	fast;
	
	cin>>L;
	
	DEC(i,20,0){
		if (L & (1<<i)){
			msb = i;
			break;
		}
	}
	
	int N = msb + 1;
	
	FOR(i,1,N-1){
		edges.pb(pii(pi(i,i+1),0));
		edges.pb(pii(pi(i,i+1),(1 << (i-1))));
	}
	
	L -= (1<<msb);
	
	int mx = (1<<msb);
	FOR(i,0,20){
		if (L & (1<<i)){
			edges.pb(pii(pi(i+1,N),mx));
			mx += (1<<i);
		}
	}
	
	cout<<N<<' '<<edges.size()<<'\n';
	
	aFOR(i,edges){
		cout<<i.f.f<<' '<<i.f.s<<' '<<i.s<<'\n';
	}
}

