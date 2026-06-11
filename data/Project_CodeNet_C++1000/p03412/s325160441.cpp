#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<int> A, B, B0, B1;

int get_value(int v, int b)
{
	return (1 << b) - (v&((1 << b) - 1)) - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, ans = 0;
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int b = 0; b < 29; b++) {
		int MOD = (1 << b) - 1;
		B0.clear();
		B1.clear();
		for (int i = 0; i < N; i++) {
			if (B[i] & (1 << b)) B1.push_back(B[i] & MOD);
			else B0.push_back(B[i] & MOD);
		}
		sort(B0.begin(), B0.end());
		sort(B1.begin(), B1.end());
		for (int i = 0; i < N; i++) {
			int cnt;
			if (A[i] & (1 << b)) {
				cnt = B1.size() - (upper_bound(B1.begin(), B1.end(), get_value(A[i], b)) - B1.begin()) + (upper_bound(B0.begin(), B0.end(), get_value(A[i], b)) - B0.begin());
			}
			else {
				cnt = B0.size() - (upper_bound(B0.begin(), B0.end(), get_value(A[i], b)) - B0.begin()) + (upper_bound(B1.begin(), B1.end(), get_value(A[i], b)) - B1.begin());
			}
			ans ^= (cnt & 1) << b;
		}
	}
	cout << ans << '\n';
	return 0;
}