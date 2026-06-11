#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	char str[10]; cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) cout << (char)('1' + '9' - str[i]);
	cout << "\n";
	
	return 0;
}
