#include<iostream>
#include<cmath>
using namespace std;

int b[110];
int main() {
	int n, m, c;
	int a;
	cin >> n >> m >> c;
	long long sum;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int i = 1; i <= m;i++) {
			cin >> a;
			sum += a * b[i];
		}
		sum += c;
		if (sum > 0)cnt++;
	}
	cout << cnt << endl;
	return 0;
}