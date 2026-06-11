#include<iostream>
using namespace std;
int main(void) {
	//入力
	int n;
	cin >> n;
	int a[100001];
	a[0] = 0;
	for (int i(1); i <=n; i++) {
		cin >> a[i];
	}
	a[n + 1] = 0;
	//処理
	bool change_sign[100001];
	for (int i(1); i <=n; i++) {
		if ((a[i] - a[i - 1])*(a[i + 1] - a[i]) < 0)change_sign[i] = true;
		else change_sign[i] = false;
	}
	int first_money(0);
	for (int i(1); i <= n+1; i++) {
		first_money += abs(a[i]-a[i-1]);
	}
	//cout << first_money << endl;
	for (int i(1); i <= n; i++) {
		if (change_sign[i]) {
			if (abs(a[i]-a[i-1])>abs(a[i+1]-a[i])) {
				cout << first_money - abs(a[i+1] - a[i]) * 2 << endl;
			}
			else {
				cout << first_money - abs(a[i] - a[i - 1]) * 2 << endl;
			}
		}
		else cout << first_money << endl;
	}
	return 0;
}