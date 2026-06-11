#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // 支払金額
    int a; // 1円の枚数

    cin >> n >> a;

    // 支払金額から500円玉で支払える分だけ引く
    n = n - ((n / 500) * 500);
	
    // 残額が1円の枚数より多ければYes
    if (n <= a) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}