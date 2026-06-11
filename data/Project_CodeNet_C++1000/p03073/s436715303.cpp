#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int ans = 0;
	for (int i = 1; i < S.size(); i++) {
		if (S[i] == S[i - 1]) {
			if (S[i] == '1') S[i] = '0';
			else S[i] = '1';
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
