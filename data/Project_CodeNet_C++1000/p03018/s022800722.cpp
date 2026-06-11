#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	string S; cin >> S;
	string T;
	long long j = 1;
	for (long long i = 0; i < S.size() - 1; i += j) {
		if (S.at(i) == 'B' && S.at(i + 1) == 'C') {
			T.push_back('D');
			j = 2;
		}
		else {
			T.push_back(S.at(i));
			j = 1;
		}
	}
	long long ans = 0, num = 0;
	for (long long i = 0; i < T.size(); i++) {
		if (T.at(i) == 'A') {
			num++;
		}
		else if (T.at(i) == 'D') {
			ans += num;
		}
		else num = 0;
	}
	cout << ans << endl;
}