#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N;
	cin >> N;
	vector<int> t(N), v(N), t_s(N+1,0);
	for (int i = 0; i < N; i++) {
		cin >> t[i];
		t_s[i + 1] = t_s[i] + t[i];
	}
	for (int i = 0; i < N; i++)cin >> v[i];

	vector<double> A;
	for (double a = 0; a <= t_s[N]; a += 0.5) {
		vector<double> v_f;
		v_f.push_back(a);
		v_f.push_back(t_s[N] - a);
		for (int i = 0; i < N; i++) {
			if (a <= t_s[i])v_f.push_back(v[i] + (t_s[i] - a));
			else if (t_s[i] < a && a <= t_s[i + 1])v_f.push_back(v[i]);
			else if (t_s[i + 1] < a)v_f.push_back(v[i] + (a - t_s[i + 1]));
		}
		A.push_back(*min_element(v_f.begin(), v_f.end()));
	}

	double ans = 0;
	for (int i = 0; i < A.size() - 1; i++) {
		ans += 0.25*(A[i] + A[i + 1]);
	}
	cout << setprecision(8) << ans << endl;
	return 0;
}