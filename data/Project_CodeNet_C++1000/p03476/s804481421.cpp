#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// [0, MaxNumPlusOne - 1 ] の範囲の整数が素数であるかどうかを表す配列を返す関数
// 配列の要素が 1であれば素数
// 配列の要素が-1であれば素数でない
vector<int> Eratosthenes(int MaxNumPlusOne) {
	vector<int> isPrimeArray(MaxNumPlusOne, 1);
	int MaxNum = MaxNumPlusOne - 1;
	isPrimeArray[0] = -1;
	isPrimeArray[1] = -1;
	for (int i = 2; i <= sqrt(MaxNum); i++) {
		if (isPrimeArray[i] == 1) {
			for (int j = 2; j <= MaxNum; j++) {
				if (i * j > MaxNum) break;
				isPrimeArray[i * j] = -1;
			}
		}
	}
	return isPrimeArray;
}

int main() {
    
    int q; cin >> q;
	const int p = 100001;
	vector<int> isPrimeNumber = Eratosthenes(p); // [0, 100000] の範囲を調べる場合
	vector<int> accum(p, 0);
	for (int i = 1; i <= p; i++) {
		accum[i] += accum[i - 1];
		if (isPrimeNumber[i] == 1 && isPrimeNumber[(i + 1) / 2] == 1) {
			accum[i]++;
		}
	}
	for (ll i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
		cout << accum[r] - accum[l - 1] << endl;
    }
    return 0;
}