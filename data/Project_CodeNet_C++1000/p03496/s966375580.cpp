#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
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
#define maxn 101
#define int ll
#define INF 1e9
int N;
int A[maxn],B[maxn],C[maxn];

int mn = INF,mx=-INF;
int mnidx,mxidx;
vpi ans;
int32_t main(){
	fast;
	
	cin>>N;
	
	bool allneg = 1, allpos = 1;
	FOR(i,1,N){
		cin>>A[i];
		B[i] = C[i] = A[i];
		if (mx < A[i]){
			mx = A[i];
			mxidx = i;
		}
		if (mn > A[i]){
			mn = min(mn,A[i]);
			mnidx = i;
		}
		
		if (A[i] > 0) allneg = 0;
		if (A[i] < 0) allpos = 0;
		
	}
		
	if (allneg){
		vpi ans;
		
		DEC(i,N-1,1){
			ans.pb(pi(i+1,i));
		}
		
		cout<<ans.size()<<'\n';
		
		aFOR(i,ans) cout<<i.f<<' '<<i.s<<'\n';
		return 0;
	}
	
	if (allpos){
		vpi ans;
		
		FOR(i,2,N){
			ans.pb(pi(i-1,i));
		}
		
		cout<<ans.size()<<'\n';
		
		aFOR(i,ans) cout<<i.f<<' '<<i.s<<'\n';
		return 0;
	}
	
	int pans = 0; vpi pvans;
	
	int tempmx = mx;
	
	while (tempmx < -mn){
		tempmx *= 2;
		pans++;
		pvans.pb(pi(mxidx,mxidx));
	}
	
	FOR(i,1,N){
		if (B[i] < 0){
			B[i] += tempmx;
			pans++;
			pvans.pb(pi(mxidx,i));
		}
	}
	
	int nans = 0; vpi nvans;
	int tempmn = mn;
	
	while (-tempmn < mx){
		tempmn *= 2;
		nans++;
		nvans.pb(pi(mnidx,mnidx));
	}
	
	FOR(i,1,N){
		if (C[i] > 0){
			C[i] += tempmn;
			nans++;
			nvans.pb(pi(mnidx,i));
		}
	}
	
	if (pans < nans){
		FOR(i,2,N){
			B[i] += B[i-1];
			pvans.pb(pi(i-1,i));
		}
		
		cout<<pvans.size()<<'\n';
		aFOR(i,pvans){
			cout<<i.f<<' '<<i.s<<'\n';
		}
	}else{
		DEC(i,N-1,1){
			B[i] += B[i+1];
			nvans.pb(pi(i+1,i));
		}
		
		cout<<nvans.size()<<'\n';
		aFOR(i,nvans){
			cout<<i.f<<' '<<i.s<<'\n';
		}
	}
	
		
	
	
	
	
	
	
	
}

