#include<iostream>
#include<cstdint>
using namespace std;

int64_t S(int64_t n) {
	int64_t ans = 0;
	while (n != 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main() {
	int K;
	cin >> K;
	int64_t n = 0, d = 1;
	for (int i = 0;i < K;i ++) {
		if ((n + d) * S(n + 10 * d) > (n + 10 * d) * S(n + d)) d *= 10;
		n += d;
		cout << n << endl;
	}
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

まず式変形、nS(m) ≦ mS(n)な訳だ
ここでn < mなのは確定的に明らかだし、S(m)≧S(n)じゃないと反例が作れないね
ここでnを下から見て最初に9でない位置をaとして、m=n+10^aとして考えてみよう
この時、mS(n) - nS(m) = (n+10^a)S(n) - n(S(n) + 1) = 10^aS(n) - nとなるね
これが0未満になるとまずいことが分かるので、aは10^a・S(n)-nが0以上になる最小のaを考えれば良い

……厳密証明ができないので端折ります、ごめんね！！
*/