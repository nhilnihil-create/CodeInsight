#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	int ans = 0;
	int a[20][20], b[1000], c;
	
	cin >> N >> M >> c;
	int sum = c;
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += a[i][j] * b[j];
		}
		if (sum > 0)ans++;
	
		sum = c;

	}
	cout << ans << endl;
	return 0;
}
