#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
inline ll ri() {
	ll r; cin >> r; return r;
}


int main()
{
	ll n, k;
	cin >> n >> k;
	priority_queue<P, vector<P>, greater<P>> que;
	priority_queue<P> unused;
	vector<vector<ll>> a(n);
	vector<ll> cntj(n);
	ll numof = 0, sum = 0;

	for(ll i = 0; i < n; i++) {
		ll t, d; cin >> t >> d; t--;
		a[t].push_back(d);
	}
	for(ll i = 0; i < n; i++) {
		sort(a[i].begin(), a[i].end(), greater<ll>());	
		if(a[i].empty())continue;
		que.push({a[i].front(), i});
		cntj[i]++;
		numof++;
		sum += a[i].front();
		for(ll j = 1; j < (ll)a[i].size(); j++)unused.emplace(a[i][j], i);
	}


	while((ll)que.size() > k) {
		cntj[que.top().second]--;
		sum -= que.top().first;
		que.pop();
		numof--;
	}
	while((ll)que.size() < k) {
		que.push(unused.top());
		cntj[unused.top().second]++;
		sum += unused.top().first;
      	unused.pop();
	}

	ll ans = sum + numof * numof;
	while(unused.size()) {
		if(--cntj[que.top().second] == 0)numof--;
		sum -= que.top().first;
		que.pop();
		if(cntj[unused.top().second]++ == 0)numof++;
		sum += unused.top().first;
		que.push(unused.top());
		unused.pop();
		ans = max(sum + numof * numof, ans);
	}
	cout << ans << endl;

}
