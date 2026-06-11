#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	ll N, M; cin >> N >> M;
	vector<ll> A(N);
	vector<pair<ll, ll>> CB(M);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		pq.push(A[i]);
	}
	ll Bsum = 0;
	for(int i = 0; i < M; i++) {
		cin >> CB[i].second >> CB[i].first;
		Bsum += CB[i].second;
	}
	sort(CB.begin(), CB.end());
	int j = M - 1, cnt = 0;
	for(int i = min(N, Bsum); i >= 0; i--) {
		ll u = pq.top();
		if(CB[j].first > u) {
			pq.pop(); pq.push(CB[j].first);
			cnt++;
			if(cnt == CB[j].second) {
				cnt = 0; j--;
			}
		}
	}
	ll ans = 0;
	while(!pq.empty()) {
		ans += pq.top(); pq.pop();
	}
	cout << ans << endl;
	return 0;
}