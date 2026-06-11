//1回の移動では、いくつかの（連続しているとは限らない）ゴミを選んで回収するとみなせる。一番遠くまで行って、帰りに回収するのが最適。
//往復回数Kを固定する
//x = {1,2,…,N}としても最適な割り振り方は変わらない。（どうせコストはΣa_i * x_iの形になるので）
//できるだけ均等な個数だけ割りふる（[2個,4個]とかだと4個の重みが大きいので、[3個,3個]とかにしたい)
//K個飛ばしの要領で拾う (遠くのやつを一気に拾うのは大変なのでできるだけ分散させて拾いたい、というお気持ち？）
//各KについてO(N)かけると400点。O(N/K)かけると700点。だと思う。
//オーバーフローが怖い

#include <iostream>
#include <algorithm>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n, c;
int x[200000];
int rx[200001];

signed main() {
	int i, j;
	
	cin >> n >> c;
	rep(i, n) cin >> x[n - 1 - i];
	rep(i, n) rx[i + 1] = rx[i] + x[i];
	
	//i往復する
	int ans = (1LL << 60);
	for (i = 1; i <= n; i++) {
		int sumCost = 0, weight = 3;
		for (j = 0; j < n; j += i) {
			sumCost += (rx[min(n, j + i)] - rx[j]) * weight;
			weight += 2;
			if (sumCost >= ans) break;
		}
		sumCost += rx[i] * 2;
		ans = min(ans, sumCost + (n + i) * c);
	}
	cout << ans << endl;
	return 0;
}