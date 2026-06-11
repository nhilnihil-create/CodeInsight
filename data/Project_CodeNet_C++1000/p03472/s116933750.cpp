#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;

typedef long long ll;
typedef long double ld;


#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)

const int INF = 2000000000; //2e9
const int large_P = 1000000007; //1e9 + 7



//繰り返し2乗法
//N^aの、Mで割った余りを求める。
ll my_pow(ll N, ll a, ll M) {
	ll tempo;
	if (a == 0) {
		return 1;
	}
	else {
		if (a % 2 == 0) {
			tempo = my_pow(N, a / 2, M);
			return (tempo * tempo) % M;
		}
		else {
			tempo = my_pow(N, a - 1, M);
			return (tempo * N) % M;
		}
	}
}



//N_C_a を M で割った余り
ll my_combination(ll N, ll a, ll M) {
	ll answer = 1;

	rep(i, a) {
		answer *= (N - i);
		answer %= M;
	}

	rep(i, a) {
		answer *= my_pow(i + 1, M - 2, M);
		answer %= M;
	}

	return answer;
}



ll my_gcd(ll& a, ll& b) {
	if (b == 0) return a;
	ll temp = a % b;
	return my_gcd(b, temp);
}



// base を底としたときの、n の i桁目を、v.at(i) に入れる。(桁数は n に応じて自動で設定する。)
void ll_to_vector(int base, long long n, vector<int>& v) {
	long long tempo = n;
	long long tempo2 = n;

	//ll n_digit = floor(log10(n) / log10(base)) + 1;  // 桁の計算を1行で。ただ誤差があるのでよくない。
	int n_digit = 1;
	while (tempo2 >= 10) {
		tempo2 /= 10;
		n_digit++;
	}

	v.assign(n_digit, 0);

	//ll n_digit = v.size();  // v のサイズをそのままにする場合。

	for (int i = 0; i < n_digit; i++) {
		v.at(i) = tempo / pow(base, n_digit - 1 - i);
		tempo -= v.at(i) * pow(base, n_digit - 1 - i);
	}
}



int char_to_int(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2; case '3': return 3; case '4': return 4;
	case '5': return 5; case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9;
	default: return 0;
	}
}


//エラトステネスの篩で、prime で ないところに false を入れる。
//true で初期化された vector を代入する必要がある。
void prime_judge(vector<bool>& prime_or_not) {

	prime_or_not.at(0) = false;
	prime_or_not.at(1) = false;

	ll n = prime_or_not.size() - 1;
	ll region = (ll)sqrt(n) + 1;

	for (ll i = 2; i <= n / 2; i++) {
		prime_or_not.at(2 * i) = false;
	}


	for (ll i2 = 1; i2 < n / 2; i2++) {
		ll i = 2 * i2 + 1;  //ここからは奇数のみ探索
		if (i < region && prime_or_not.at(i)) {
			ll j = i * i;
			while (j < n + 1) {
				prime_or_not.at(j) = false;
				j += 2 * i;
			}
		}
	}
};



map<ll, ll> divide_to_prime(int target) {
	map<ll, ll> res;

	//sqrt(target) まで調べる。
	ll upper_lim = ceil(sqrt(target));
	vector<bool> prime_or_not(upper_lim + 1, true);

	if (upper_lim < 20) prime_or_not.assign(25, true);
	prime_judge(prime_or_not);

	ll tempo = target;
	rep(i, (upper_lim + 1)) {
		if (prime_or_not.at(i)) {
			while (tempo % i == 0) {
				tempo /= i;
				res[i]++;
			}
		}
	}

	if (tempo != 1) res[tempo]++; //sqrt(target) より大きな素因数は高々1つしかない。



	return res;
}



void BFS_labyrinth(queue<pair<int, int>>& que, vector<vector<int>>& dist, int& area) {
	int n = dist.size();
	int m = dist.at(0).size();

	while (!que.empty()) {
		int temp_i, temp_j;
		pair<int, int> tempo = que.front(); que.pop();

		temp_i = tempo.first;
		temp_j = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (temp_i + i < 0 || n <= temp_i + i) continue;  //範囲外
				if (temp_j + j < 0 || m <= temp_j + j) continue;  //範囲外
				if (i == 0 && j == 0) continue; //動いていない
				if (i * j != 0) continue; //右上など
				if (dist.at(temp_i + i).at(temp_j + j) != -1) continue; //行けない領域に、既に INF などが代入されている場合はこの条件だけで ok

				dist.at(temp_i + i).at(temp_j + j) = dist.at(temp_i).at(temp_j) + 1;
				que.push(make_pair(temp_i + i, temp_j + j));
			}
		}

		//何か所も領域がある場合だけ必要
		if (que.empty()) {
			rep(i, n) {
				rep(j, m) {
					if (dist.at(i).at(j) == -1) {
						que.push(make_pair(i, j));
						dist.at(i).at(j) = 0;
						area++;
						break;
					}
				}
				if (!que.empty()) break;
			}
		}
	}
}



signed main() {
	int N, H;
	cin >> N >> H;

	vector<int> a(N), b(N);
	rep(i, N) cin >> a.at(i) >> b.at(i);

	vector<pair<int, int>> attack(2 * N);

	rep(i, N) {
		attack.at(i) = make_pair(a.at(i), i);
	}
	rep(i, N) {
		attack.at(i + N) = make_pair(b.at(i), i + N);
	}

	sort(attack.begin(), attack.end());

	int i = 2 * N - 1;
	int res = 0;
	while (attack.at(i).second >= N && H > 0) {
		H -= attack.at(i).first;
		res++;
		i--;
	}

	if (H > 0) {
		if (H % attack.at(i).first == 0) res += H / attack.at(i).first;
		else res += H / attack.at(i).first + 1;
	}


	cout << res << endl;
}