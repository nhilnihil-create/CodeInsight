#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
const ll MOD = 1000000007;

int main(){
	int N, L, R;
	cin >> N;
	vector<pair<int, int>> sg(N + 1);
	for (int i = 0;i < N;i++) {
		cin >> L >> R;
		sg[i] = { L + 100001,R + 100001 };
	}
	sg[N] = { 100001,100001 };
	vector<int> AC(200010, 0), WA = AC;
	for (int i = 0;i <= N;i++) {
		AC[sg[i].second]++;
		WA[sg[i].first - 1]++;
	}
	for (int i = 0;i < 200009;i++) {
		AC[i + 1] += AC[i];
		WA[200008 - i] += WA[200009 - i];
	}
	ll ans = 0;
	for (int i = 0;i < 200009;i++) {
		ans += (ll)min(AC[i], WA[i]);
	}
	cout << ans * 2 << endl;
}