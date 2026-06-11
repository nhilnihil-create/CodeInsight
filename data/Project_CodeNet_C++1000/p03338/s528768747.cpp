#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int arr[256] = { 0 }, sum = 0;

			for (int k = i; k < j; k++) {
				arr[(int)s[k]]++;
			}
			for (int k = j; k < n; k++) {
				if (arr[(int)s[k]] > 0) {
					sum++;
					arr[(int)s[k]] = 0;
				}
			}
			ans = max(ans, sum);

		}
	}

	printf("%d\n", ans);
}

