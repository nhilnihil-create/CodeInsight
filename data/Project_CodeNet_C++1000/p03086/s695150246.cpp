#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string S;
	cin >> S;

	int size = S.size();

	int ans = 0;
	for (int ii = 0; ii < size; ++ii){
		for (int len = 0; len <= size - ii; ++len){
			string t = S.substr(ii, len);

			int tsize = t.size();
			bool ok = true;
			for (int jj = 0; jj < tsize; ++jj){
				if ( (t[jj]!='A') && (t[jj]!='C') &&(t[jj]!='G') &&(t[jj]!='T') ){
					ok = false;
					break;
				}
			}

			if (ok){
				ans = max(ans, tsize);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
