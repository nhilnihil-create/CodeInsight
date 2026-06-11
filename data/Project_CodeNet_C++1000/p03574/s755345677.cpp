#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
char arr[60][60];
int ans[60][60];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '.')
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						if (i + k >= 0 && i + k < n && j + l >= 0 && j + l < m)
							if (arr[i + k][j + l] == '#')
								ans[i][j]++;
					}
				}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#')
				cout << arr[i][j];
			else
				cout << ans[i][j];
		}
		printf("\n");
	}
}

