#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	string S;
	cin >> S;

	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'W') {
			ans += i - cnt;
			cnt += 1;
		}
	}

	cout << ans << endl;

	return 0;
}