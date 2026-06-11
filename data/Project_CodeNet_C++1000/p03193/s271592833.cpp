#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, h, w, a, b, sum = 0; cin >> n >> h >> w;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (a >= h && b >= w) {
			sum++;
		}
	}
	cout << sum << endl;
	cin >> n;
}