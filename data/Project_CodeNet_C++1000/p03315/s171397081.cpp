#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == '+')cnt++;
		else cnt--;
	}
	cout << cnt;
}
















