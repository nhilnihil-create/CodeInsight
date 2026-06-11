#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e11;

int main(){
	long long A, B, Q;
	cin >> A >> B >> Q;
	vector<long long> s(A + 2), t(B + 2), x(Q);
	for (long long i = 1; i <= A; i++){
		cin >> s[i];
	}
	for (long long i = 1; i <= B; i++){
		cin >> t[i];
	}
	s[0] = -INF;
	s[A + 1] = INF;
	t[0] = -INF;
	t[B + 1] = INF;

	for (long long i = 0; i < Q; i++){
		long long x;
		cin >> x;

		long long sindex = distance(s.begin(), lower_bound(s.begin(), s.end(), x));
		long long tindex = distance(t.begin(), lower_bound(t.begin(), t.end(), x));

		long long ans = INF;
		ans = min(ans, abs(s[sindex - 1] - x) + abs(t[tindex - 1] - s[sindex - 1]));
		ans = min(ans, abs(t[tindex - 1] - x) + abs(s[sindex - 1] - t[tindex - 1]));

		ans = min(ans, abs(s[sindex] - x) + abs(t[tindex - 1] - s[sindex]));
		ans = min(ans, abs(t[tindex - 1] - x) + abs(s[sindex] - t[tindex - 1]));
		
		ans = min(ans, abs(s[sindex - 1] - x) + abs(t[tindex] - s[sindex - 1]));
		ans = min(ans, abs(t[tindex] - x) + abs(s[sindex - 1] - t[tindex]));
		
		ans = min(ans, abs(s[sindex] - x) + abs(t[tindex] - s[sindex]));
		ans = min(ans, abs(t[tindex] - x) + abs(s[sindex] - t[tindex]));

		cout << ans << endl;
	}

	return 0;
}
