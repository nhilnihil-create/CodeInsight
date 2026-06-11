#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main() {
	int n, ans = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			bool left = false, right = false;
			for (int j = 0; j < i; j++) {
				if (s.at(j) == c) left = true;
			}
			for (int j = i; j < n; j++) {
				if (s.at(j) == c) right = true;
			}
			if (left && right)
				cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}