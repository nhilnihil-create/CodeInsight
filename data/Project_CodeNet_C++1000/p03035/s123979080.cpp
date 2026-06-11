//標準関数をすべてインクルードする。
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int_least64_t INF = 10000000;

int main(){
    //cin coutを高速化
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

    int A, B;
    cin >> A >> B;

    if(A <= 5) B = 0;
    if(A >= 6 && A <= 12) B = B / 2;
    
    cout << B << endl;

    return 0;
}

