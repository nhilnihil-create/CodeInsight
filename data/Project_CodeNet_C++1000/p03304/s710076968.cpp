// 解説見た
#include <bits/stdc++.h>
using namespace std;
int main() {
	double n,m,d; cin >> n >> m >> d;
	if (d==0) {
		cout << std::fixed << std::setprecision(15) << (m-1) / n << endl;
	}
	else {
		cout << std::fixed << std::setprecision(15) << 2 * (n-d) * (m-1) / pow(n,2) << endl;
	}
}