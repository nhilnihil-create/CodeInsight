#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int ans = 0;
	for (int i = 0; i < S.length(); i++) {
		int cnt = 0;
		for (int j = i; j < S.length(); j++) {
			if (S[j] == 'A' || S[j] == 'C' || S[j] == 'G' || S[j] == 'T') {
				cnt++;
			} else {
				break;
			}
		}
		// cout << i << "  " << cnt << "\n";
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);

	return 0;
}
