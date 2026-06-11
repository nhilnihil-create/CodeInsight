#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<string, string> P;
const ll MOD = 1000000007LL;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	map<P, int> cnt;
	for (int bit = 0; bit < (1 << N); bit++) {
		string a = "", b = "";
		for (int i = 0; i < N; i++) {
			if (bit&(1 << i)) a.push_back(S[i]);
			else b.push_back(S[i]);
		}
		cnt[P(a, b)]++;
	}
	ll ans = 0;
	for (int bit = 0; bit < (1 << N); bit++) {
		string a = "", b = "";
		for (int i = 0; i < N; i++) {
			if (bit&(1 << i)) b.push_back(S[i + N]);
			else a.push_back(S[i + N]);
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		ans += cnt[P(a, b)];
	}
	cout << ans << endl;
}