#include <bits/stdc++.h>
using namespace std;
#define MODNUMBER 1000000007

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	int N;
	char s;
	scanf("%d", &N);
	scanf("%c", &s);  // 改行文字空読み

	vector<int> c_num(26, 0);
	for (int i = 0; i < N; i++) {
		scanf("%c", &s);
		c_num[s - 'a']++;
	}

	long long result = 1;
	for (int i = 0; i < 26; i++) {
		result = (result * (c_num[i] + 1)) % MODNUMBER;
	}

	result = ((result - 1) + MODNUMBER) % MODNUMBER;
	cout << result;
	return 0;
}