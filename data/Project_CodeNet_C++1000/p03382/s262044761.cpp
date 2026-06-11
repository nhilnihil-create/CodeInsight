#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<int> A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, m;
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	m = upper_bound(A.begin(), A.end(), A[N - 1] / 2) - A.begin();
	if (m == 0 || (A[N - 1] + 1) / 2 - min(A[m], A[N - 1] - A[m]) < (A[N - 1] + 1) / 2 - min(A[m - 1], A[N - 1] - A[m - 1])) cout << A[N - 1] << ' ' << A[m] << '\n';
	else cout << A[N - 1] << ' ' << A[m - 1] << '\n';
	return 0;
}