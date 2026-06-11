#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<list>
using namespace std;

int main() {

	string S;
	cin >> S;

	int ans = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '+') {
			ans += 1;
		}
		else {
			ans -= 1;
		}
	}
	
	cout << ans << endl;

	return 0;
}
