#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int ans = 1000;
	for (int i = 0; i < S.length() - 2; i++) {
		int num = atoi(S.substr(i, 3).c_str());
		// cout << num << "\n";
		ans = min(ans, abs(num - 753));
	}
	printf("%d\n", ans);
	return 0;
}
