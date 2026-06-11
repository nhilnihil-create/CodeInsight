#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;
	S.length();
	int ans = 0, cnt = 0;

	for (int i = 0; i < S.length(); i++) {
		char a = S[i];
		if (a == 'A' || a == 'C' || a == 'G' || a == 'T') {
			 cnt++;
		}
		else {
			cnt = 0;
		}
		ans = max(cnt, ans);


	}


	cout << ans << endl;
	return 0;
}