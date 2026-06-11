#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s;
	
	int s_len = (int)s.size();
	int zero_cnt = count(s.begin(), s.end(), '0');
	int one_cnt = count(s.begin(), s.end(), '1');

	int ans = s_len - abs(zero_cnt - one_cnt);

	printf("%d\n", ans);

	return 0;
}