#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<' '
typedef long long ll;
typedef pair<int,int> pi;

bool cmp(pi a, pi b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pi> v1,v2;
	vector<int> used(N);
	for (int i = 0; i < N; i++) {
		int a,b; cin >> a >> b;
		v1.emplace_back(a,b); // red
	}
	for (int i = 0; i  < N; i++) {
		int a,b; cin >> a >> b;
		v2.emplace_back(a,b); // blue
	}
	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!used[j] && v1[j].second < v2[i].second && v1[j].first < v2[i].first) {
				ans++;
				used[j] = 1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
