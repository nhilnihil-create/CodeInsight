#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
using namespace std;

int main() {
	long long cnt = 0, ans = 1, sum = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B') {
			cnt++;
		}
		else if (s[i] == 'W') {
			ans = ans * cnt;
			sum = sum + ans;
			ans = 1;
		}
	}
	cout << sum << endl;
}