#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string S;
	cin >> S;

	int ans = 0;
	int n = S.size();

	for (int ii = 0; ii < n; ++ii){
		for (int len = 1; len <= n - ii; ++len){
			string tmp = S.substr(ii, len);
			bool ok = true;
			for (int kk = 0; kk < len; ++kk){
				bool cond1 = (tmp[kk] == 'A');
				bool cond2 = (tmp[kk] == 'C');
				bool cond3 = (tmp[kk] == 'G');
				bool cond4 = (tmp[kk] == 'T');
				if (cond1||cond2||cond3||cond4){
				} else {
					ok = false;
				}
			}
			if (ok){
				ans = max(ans, len);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
