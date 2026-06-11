#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*
 * k <= a % b
 * ありうる(a,b)の組を求めよ
 *
 * どこで計算量を落とすか
 * b > a のとき, あまりは絶対a(a < b <= n)
 * b <= a のとき, 余りは0~a-1で周期を持つ
 *
 * bを固定(b < a)
 * ex) b = 5, k = 3 ..余り3or4のときだけ
 * (n/5) * (b-k)
 * s = (n/5) * 5とおくと,
 * あとは, s+1~nまでの余りを考えればOK
 */
ll n, k;

int main() {
	cin >> n >> k;
	if(k==0) {
		cout << n*n << endl;
		return 0;
	}
	ll cnt = 0;
	for(ll b=1;b<=n;b++) {
		cnt += (n/b)*max((ll)0, b-k);
		if(n%b >= k) {
			cnt += (n%b - k + 1);
		}
	}
	/*
	// a < k のとき: そもそも無理(理由: あまり0~a < k)
	for(int a=k;a<=n;a++) {
		for(int b=1;b<=a;b++) {
			if(a%b >= k)
				cnt++;
		}
		if(a >= k)
			cnt += (n-a);
	}
	*/
	cout << cnt << endl;
}