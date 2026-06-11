#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;

int main() { 
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	//int cnt = 0;
	string p = "0123456789";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') {
				int cnt = 0;
				if (i + 1 < n && s[i + 1][j] == '#') cnt++;
				if (j + 1 < m && s[i][j + 1] == '#') cnt++;
				if (i - 1 >= 0 && s[i - 1][j] == '#') cnt++;
				if (j - 1 >= 0 && s[i][j - 1] == '#') cnt++;
				if (i + 1 < n && j + 1 < m && s[i + 1][j + 1] == '#') cnt++;
				if (i + 1 < n && j - 1 >= 0 && s[i + 1][j - 1] == '#') cnt++;
				if (i - 1 >= 0 && j + 1 < m && s[i - 1][j + 1] == '#') cnt++;
				if (i - 1 >= 0 && j - 1 >= 0 && s[i - 1][j - 1] == '#') cnt++;
				s[i][j] = p[cnt]; 
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << s[i] << endl;
	}
	return 0; 
} 

