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

	int q;
	cin >> q;
	int l, r;
	vector<int> pp(100010);
	for (int i = 1; i <= 100000; i++) {
		pp[i] = IsPrime(i) & IsPrime((i+1)/2);
	}
	vector<int> ppp(100010);
	for (int i = 1; i <= 100000; i++) {
		ppp[i] = ppp[i - 1] + pp[i];
	}

	for (int j = 0; j < q; j++) {
		cin >> l >> r;

		cout << ppp[r]-ppp[l-1] << endl;
	}
}