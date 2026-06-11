#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int N;
	double ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		double x;
		string v;
		cin >> x >> v;
		if (v == "JPY") {
			ans += x;
		}
		else if (v == "BTC") {
			ans += x * 380000;
		}
	}

	cout << fixed << setprecision(4) << ans << endl;
}