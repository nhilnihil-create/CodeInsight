#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {         
	int n, m;
	cin >> n >> m;
	char v[n][m];
    bool d = 1;
    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == '#') {
				int cnt = 0;
				if (i + 1 < n && v[i + 1][j] == '#')cnt++;
				if (i - 1 >= 0 && v[i - 1][j] == '#')cnt++;
				if (j + 1 < m && v[i][j + 1] == '#')cnt++;
				if (j - 1 >= 0 && v[i][j -1] == '#')cnt++;
				if (!cnt) {
					d = 0;
				} 
			}
		}
	}
    if (d) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}
