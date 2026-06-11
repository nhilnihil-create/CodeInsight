#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	int k = S.length();

	int win = 0;
	for (int i = 0; i < k; i++) {
		if (S[i] == 'o') {
			win++;
		}
	}

	if (win + (15 - k) >= 8) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
