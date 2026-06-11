#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	char arr[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') {
				bool flag = 0;
				if (i + 1 < n && arr[i + 1][j] == '#')
					flag = 1;
				if (i - 1 >= 0 && arr[i - 1][j] == '#')
					flag = 1;
				if (j + 1 < m && arr[i][j + 1] == '#')
					flag = 1;
				if (j - 1 >= 0 && arr[i][j - 1] == '#')
					flag = 1;
				if (!flag) {
					return printf("No\n"), 0;
				}

			}
		}

	}
	printf("Yes\n");
}
