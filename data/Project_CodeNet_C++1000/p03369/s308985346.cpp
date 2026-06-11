#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string S;
	cin >> S;

	int ans = 700;

	for (int i = 0; i < S.size(); i++) {
		int x = 100;

		if (S[i] == 'o') {
			ans += x;
		}
	}
	cout << ans << endl;
}

