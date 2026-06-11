//大文字->小文字 tolower(),逆はtoupper()
//int a = stoi(c); 文字列をintへ
//途中の出力をそのまま残すな
//数値計算 基本はdouble
#include <bits/stdc++.h>
#define ALL(a) (a).begin(),(a).end()
#define ll long long int
using namespace std;

int dig(int N) {//桁数
	int dig = 0;
	while (N) {
		dig++;
		N /= 10;
	}
	return dig;
}

int main() {
	int A, B; cin >> A >> B;
	if (B%A == 0)cout << A + B << endl;
	else cout << B - A << endl;
}