#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)

const int inf = 1e9 + 5;

signed main()
{
	int N; cin >> N;
	vector<int> A(N), B(N);
	int sum = 0;
	int mn = inf;
	rep(i, N) {
		cin >> A[i] >> B[i];
		if (A[i] > B[i]) {
			if (mn > B[i]) mn = B[i];
		}
		sum += A[i];
	}

	bool flag = true;

	rep(i, N) flag &= (A[i] == B[i]);

	if (flag) {
		cout << 0 << endl;
		return 0;
	}

	if (mn == inf) {
		cout << sum << endl;
	} else {
		cout << sum - mn << endl;
	}
}

