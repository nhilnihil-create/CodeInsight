#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<time.h>
#include<tuple>
#include<utility>
#include<vector>

using namespace std;

int main() {

	long N, K; cin >> N >> K;
	long res = 0;

	for (int b = 1; b <= N; b++) {
		//bで割ったあまりがK以上となるN以下の整数
		//余りは0 ~ b - 1;
		//剰余類の中の候補数
		long overK = max(b - K, (long)0);

		//Kが0でないときN以下の非負整数とできる
		long maxbs = N - (N % b); // N以下の最大のbの倍数
		long perfdivg = maxbs / b;//N以下のb-完全剰余類の数は
		res += overK * perfdivg;
		maxbs += K; //余りをK以上に
		res += max((long)0, N - maxbs + 1);//残りの候補

	}
    if (K == 0) res -= N; // (a == 0)を省く
	cout << res << endl;

}