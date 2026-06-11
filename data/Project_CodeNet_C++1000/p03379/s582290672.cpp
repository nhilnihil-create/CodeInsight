#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	//入力
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> sortx(n);
	rep(i, n) {
		cin >> x[i];
		sortx[i]= x[i];
	}
	//sort
	sort(sortx.begin(), sortx.end());
	//答え
	rep(i,n) {
		if (x[i] <= sortx[n / 2 - 1]) {
			std::cout << sortx[n / 2] << endl;
		}
		else {
			std::cout << sortx[n / 2 - 1] << endl;
		}
	}
}
