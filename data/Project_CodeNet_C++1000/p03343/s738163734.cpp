#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k, q; cin >> n >> k >> q;
	vector<int> a(n);
	for(auto &i:a) cin >> i;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for(int i=0; i<n; ++i) pq.push(make_pair(a[i], i));
	vector<int> b(n);
	int ans = n == 1 ? 0 : 1e9;
	for(int i=0; i<n-q; ++i){
		priority_queue<int, vector<int>, greater<>> p;
		for(int j=0; j<n; ++j){
			priority_queue<int, vector<int>, greater<>> r;
			for(int l=0; l<k-1; ++l) r.push(a[j+l]);
			for(int l=j; l<n; ++l){
				if(b[l] == 1){
					j = l;
					break;
				}
				if(l-j+1 >= k) r.push(a[l]);
				if(l == n-1) j = n-1;
			}
			int m = max(0, (int)r.size()-k+1);
			for(int l=0; l<m; ++l){
				p.push(r.top());
				r.pop();
			}
		}
		if(p.size() < q) break;
		int mi = p.top();
		for(int j=0; j<q-1; ++j) p.pop();
		int ma = p.top();
		ans = min(ans, ma - mi);
		pair<int, int> x = pq.top(); pq.pop();
		b[x.second] = 1;
	}
	cout << ans << "\n";
}