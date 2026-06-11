#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
    if (s[k-1] >= 'A' && s[k-1] <= 'Z') {
        int c;
        c = s[k-1] - 'A';
        s[k-1] = c + 'a';
        cout << s;
    }
	return 0;
}