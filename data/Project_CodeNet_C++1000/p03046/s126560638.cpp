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
#define pf push_front
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
int M,K;
deque <int> ans;

bool vis[300001];

int ans1[6] = {3,1,3,2,1,2};

int main(){
	fast;
  	cin>>M>>K;
	
	if (K > (1<<M) - 1){
		cout<<-1;
		return 0;
	}
	
	if (ceil(log2(K)) == floor(log2(K)) && K != 0){
		if (K+1 > (1<<M) - 1){
			cout<<-1;
			return 0;
		}
		
		if (K == 1){
			if (3 > (1<<M) - 1){
				cout<<-1;
				return 0;
			}
			ans.pb(K); ans.pb(3); ans.pf(3); ans.pb(2); ans.pf(2);
			vis[3] = vis[2] = vis[1] = 1;
		}else{
			ans.pb(K); ans.pb(K+1); ans.pf(K+1); ans.pb(1); ans.pf(1);
			vis[K] = vis[K+1] = vis[1] =  1;
		}
		
		FOR(i,0,(1<<M) - 1){
			if (!vis[i]) ans.pb(i), ans.pf(i);
		}
		
		ans.pb(K);
		while (!ans.empty()) cout<<ans.front()<<' ', ans.pop_front();
		return 0;
		
	}
	
	if (K == 0){
		FOR(i,0,(1<<M) - 1) ans.pb(i),ans.pf(i);
		
		while (!ans.empty()) cout<<ans.front()<<' ',ans.pop_front();
		return 0;
	}
	ans.pb(K);
	
	vis[K] = 1;
	FOR(i,0,M){
		if (K & (1<<i)){
			ans.pb((1<<i));
			ans.pf((1<<i));
			vis[(1<<i)] = 1;
		}
	}
	
	
	
	
	FOR(i,0,(1<<M)-1){
		if (!vis[i]){
			ans.pb(i);
			ans.pf(i);
		}
	}
	ans.pb(K);
	
	while (!ans.empty()){
		cout<<ans.front()<<' ';
		ans.pop_front();
	}
	
}
      	
	


