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
#define INF 1e10
#define maxn 2001
#define int ll
int N,K,Q;
int A[2001];



int32_t main(){
	fast;
	
	cin>>N>>K>>Q;
	
	FOR(i,0,N-1) cin>>A[i];
	

	int ans = INF;
	FOR(i,0,N-1){
		
		vi ranges[maxn];
		vi cur; int idx = 0;
		bool np = 0;
		FOR(j,0,N-1){
			if (A[j] < A[i]){
				aFOR(i,cur) ranges[idx].pb(i);
				idx++;
				while (!cur.empty()) cur.pop_back();
			}else cur.pb(A[j]);
		}
		
		ranges[idx] = cur;
	

		

		
		FOR(j,0,idx){
			if (ranges[j].empty()) continue;
			sort(all(ranges[j]));
			ranges[j].resize(max((int)0,(int)ranges[j].size() - K + 1));
			sort(all(ranges[j]),greater<int>());
		}
		
		multiset <pi> current;
		
		FOR(j,0,idx) if (!ranges[j].empty()) current.insert(pi(ranges[j][ranges[j].size() - 1],j));

		int mx = 0;
		FOR(j,0,Q-1){
			if (current.empty()){
				np = 1;
				break;
			}
			mx = max(mx,(*current.begin()).f);
			
			ranges[(*current.begin()).s].pop_back();
			int index = (*current.begin()).s;
			current.erase(*current.begin());
			if (!ranges[index].empty()) current.insert(pi(ranges[index][ranges[index].size()-1],index));
			
			
		}
		if (np) continue;
		
		//cout<<mx<<' '<<A[i]<<'\n';
		ans = min(ans,mx - A[i]);
		if (ans == 237958691){
			cout<<A[i]<<' '<<mx<<' ';
			break;
		}
		
	}
	
	cout<<ans;
		
}

