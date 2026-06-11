#include<iostream>
#include<algorithm>
using Int = long long;
const Int INF = 1 << 30;

int main() {

	Int A, B, C, X, Y;
	std::cin >> A >> B >> C >> X >> Y;

	Int ans = INF;
	Int c_limit = std::max(X, Y)*2;

	for (Int i = 0; i <= c_limit; i++) {
		Int a = std::max(0LL,X - i/2);//aを買う枚数
		Int b = std::max(0LL,Y - i/2);//bを買う枚数
		//if (b <= 0)b = 0;
		Int sum = a * A + b * B + i * C;
		if (sum <= ans)ans = sum;
	}

	std::cout << ans << std::endl;

}