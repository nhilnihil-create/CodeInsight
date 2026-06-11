#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 2e5+5;
ll n, k, arr[nax];
set<ll>s;
vector<ll>store;
vector<ll>cnt(nax);
bool vis[nax];
	
int main(){
	IOS
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		cnt[arr[i]]++;
		s.insert(arr[i]);
	}
	for(int i=0;i<n;i++){
		if(vis[arr[i]]) continue;
		vis[arr[i]]=1;
		store.pb(cnt[arr[i]]);
	}
	sort(store.begin(), store.end());
	ll ans=0, sais=s.size();
	if(sais<=k){
		cout << 0 << '\n';
		return 0;
	}
	for(int i=0;i<(sais-k);i++){
		ans+=store[i];
	}
	cout << ans << '\n';
}
