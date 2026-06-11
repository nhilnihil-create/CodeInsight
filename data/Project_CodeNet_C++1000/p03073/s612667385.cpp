#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int N = s.size();
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if ((s[i] + i) % 2 == 0) ++cnt;
	}
	cout << min(cnt, N - cnt) << endl;
	return 0;
}