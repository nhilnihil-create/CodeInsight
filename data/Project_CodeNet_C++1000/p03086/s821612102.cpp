#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	string S;

	cin >> S;
	int count = 0, ans = 0;
	rep(i, S.size()) {
		if (S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
			count++;
		}
		else {
			count = 0;
		}

		if (ans < count)
		{
			ans = count;
		}

	}
	cout << ans << endl;


}