#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mod 1000000007
#define dbg if(debug)
using namespace std;
const bool debug = 0;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> h(n),a(n);
	for(int &x: h)
		cin>>x;
	for(int &x: a)
		cin>>x;

	map<int,ll> mp;
	mp[0] = 0;

	for(int i=0;i<n;++i){
		int x = h[i];
		auto it = mp.lower_bound(x);
		--it;
		auto its = it;
		++it;
		while(it!=mp.end() && it->ss<=its->ss+a[i]){
			mp.erase(it);
			it = mp.lower_bound(x);
		}
		mp[x] = max(mp[x],its->ss+a[i]);
	}
	ll ans=0;
	for(auto it: mp){
		ans = max(ans,it.ss);
	}
	cout<<ans;

	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}