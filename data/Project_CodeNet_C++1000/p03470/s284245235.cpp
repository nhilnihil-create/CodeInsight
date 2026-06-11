#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N;
	cin >> N;

    vector<int> mochi(101, 0);

	for (int loop = 0; loop < N; ++loop) {
		int d;
		cin >> d;
		mochi[d] = 1;
	}

	int ans = 0;
	for (int loop = 1; loop < 101; ++loop) {
		ans += mochi[loop];
	}

	cout << ans << endl;
 
	return 0;
}
