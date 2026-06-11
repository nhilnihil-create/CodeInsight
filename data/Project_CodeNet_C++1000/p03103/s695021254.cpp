#include <cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	vector<P>p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(), p.end());
	ll count = 0;
	for (int i = 0; i < n; i++) {
		count += p[i].second;
		if (count >= m) {
			sum += p[i].first * p[i].second;
			sum -= p[i].first * (count - m);
			break;
		}
		else {
			sum += p[i].first * p[i].second;
		}
		
	}
	cout << sum << endl;
	return 0;
}
