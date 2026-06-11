#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S;

int main(void) {
	cin >> S;
	int cnt_0 = count(S.begin(), S.end(), '0');
	int cnt_1 = S.length() - cnt_0;
	int cnt = min(cnt_0, cnt_1);
	cout << cnt * 2 << '\n';
	return 0;
}
