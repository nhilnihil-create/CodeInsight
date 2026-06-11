#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

int main() {
	
	vector<int> a(100010);
	for (int i = 3; i <= 100000; i=i+2) {

		a[i] = a[i - 2] + (IsPrime(i) && IsPrime((i + 1) / 2));
	}


	int q;
	cin >> q;
	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		if (l != 1) {
			cout << a[r] - a[l - 2] << endl;
		}
		else {
			cout << a[r] << endl;
		}
	}



}