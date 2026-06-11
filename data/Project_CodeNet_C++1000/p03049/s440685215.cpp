//大文字->小文字 tolower(),逆はtoupper()
//int a = stoi(c); 文字列をintへ
//途中の出力をそのまま残さない
//数値計算 個数以外はdouble
//map<キー,値> p は辞書。p[キー] = 値
//map 全探索
//auto begin = p.begin(), end = p.end();
//for (auto it = begin; it != end; it++) {}
//mapのキー：it->first mapのバリュー：it->second
//絶対値 abs()
//入力は空白で切れる
//大文字判定 isupper(文字) 小文字判定 islower(文字)
//do{}while(next_permutation(ALL(配列)))
//while(N)で回すとき、Nはコピーを作っておく
//vector<ll> cue: キューの宣言
//n重ループ：初期化の位置に注意
#include <bits/stdc++.h>
#define rep(i,N) for(int i = 0; i < N;i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long int
using namespace std;

// K進数でのNの桁数
ll dig(ll N, ll K) {
	ll dig = 0;
	while (N) {
		dig++;
		N /= K;
	}
	return dig;
}
// x,yの最大公約数
ll gcd(ll x, ll y) {
	ll r;
	while (x%y) {
		r = x % y;
		x = y;
		y = r;
	}
	return y;
}

//nC2の計算
ll C(ll N) {
	return N * (N - 1) / 2;
}

ll a(ll n, ll x) {
	ll r = pow(10, x);
	n = (n % r);
	n /= pow(10, x - 1);
	return n;
}

int main() {
	ll N; cin >> N;
	string s[N]; rep(i, N)cin >> s[i];

	ll a = 0, b = 0, ab = 0;
	rep(i, N) {
		if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') ab++;
		else if (s[i][s[i].size() - 1] == 'A')a++;
		else if (s[i][0] == 'B')b++;
	}

	ll ans = 0;
	rep(i, N) {
		for (int j = 0; j <= s[i].size() - 2; j++) {
			if (s[i][j] == 'A' && s[i][j+1] == 'B')ans++;
		}
	}

	if (ab == 0) cout << ans + min(a, b) << endl;
	else if (a + b > 0) cout << ans + ab + min(a, b) << endl;
	else cout << ans + ab - 1 << endl;
}