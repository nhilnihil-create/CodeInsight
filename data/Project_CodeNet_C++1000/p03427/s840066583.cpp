#include <bits/stdc++.h>
using namespace std;

int ans1,ans2;

string S;

int main() {
	cin >> S;
	int len = S.size();
	for(int i = 0;i < len;i++) {
		ans1 += S[i] - '0';
		if(i == 0) {
			ans2 += (S[i] - '0' - 1);
			continue;
		}
		ans2 += 9;
	}
	printf("%d\n",max(ans1,ans2));
	return 0;
}