#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cmath>
using namespace std;

#define int long long
#define endl "\n"
#define all(v)  v.begin(),v.end()
#define fir first
#define sec second
#define m_p make_pair
#define rep(i,n)  for(int i=0; i<(int) (n); i++)
#define vecin(v) for(int i=0; i<(int)v.size(); i++)cin>>v[i];
#define vecout(v) for(int i=0; i<v.size(); i++)cout<<v[i]<<" "; cout<<endl;



#define LLU long long unsigned

const int mod = 1000000007;
const int INF = 2000000015;
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];


int jousu(int x00, int y00) {
	int z00 = 1;
	for (int i = 0; i < y00; i++) {
		z00 *= x00;
	}
	return z00;
}
int keta(int x00) {
	int z00 = x00;
	int w00 = 0;
	while (z00 != 0) {
		z00 /= 10;
		w00++;
	}
	return w00;
}
int krag(double xx) {
	return INF - (int)(INF - xx);
}
//x未満の要素数を返す二分探索関数
int b_s(vector<int>&vecxx, int xx) {
	if (xx <= vecxx[0]) { //x以下の要素数を返させる時は"<"に変える
		return 0;
	}
	if (vecxx.back() < xx) { //x以下の要素数を返させる時は"<="に変える
		return vecxx.size();
	}
	int aa1 = 0, aa2 = vecxx.size() - 1, aa3;
	while (aa1 + 1 < aa2) {
		aa3 = (aa1 + aa2) / 2;
		if (vecxx[aa3] >= xx) { //x以下の要素数を返させる時は">"に変える
			aa2 = aa3;
		}
		else {
			aa1 = aa3;
		}
	}
	return aa2;
}


// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
//n個を1個以上のx組のグループに分ける重複組み合わせはcom(n-1,x-1)
//グループが0個でもいいときはnにxを足す
// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int modinv(int a, int m) {
	int b = m, u = 1, v = 0;
	while (b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int gcd(int xx, int yy) {
	int p = xx;
	int q = yy;
	if (q > p)swap(p, q);
	while (p % q != 0) {
		p %= q;
		swap(p, q);
	}
	return q;
}
int lcm(int xx, int yy) {
	return xx * yy / gcd(xx, yy);
}
bool prime(int xx) {
	int a = xx;
	for (int i = 2; i * i <= xx; i++) {
		if (xx % i == 0) {
			return 0;
		}
	}
	return 1;
}


signed main() {
	int n,a=0,b=0;
	cin >> n;
	vector<pair<int,pair<int,int>>>vec(n);
	vector<int>vec2(n);
	rep(i, n) {
		cin >> vec[i].sec.fir >> vec[i].sec.sec;
		vec[i].fir = vec[i].sec.fir + vec[i].sec.sec;
	}
	sort(all(vec));
	reverse(all(vec));
	rep(i, n) {
		if (i % 2 == 0) {
			a += vec[i].sec.fir;
		}
		else {
			b += vec[i].sec.sec;
		}
	}
	cout << a - b << endl;
}



/*
signed main() {
	int n, h, w, a, b = 0, c = 0;
	cin >> h >> w >> n;
	vector<vector<int>>vec(h, vector<int>(w));
	rep(i, n) {
		cin >> a;
		rep(j, a) {
			vec[b][c] = i + 1;
			if ((b == h - 1 && c % 2 == 0) || (b == 0 && c % 2 == 1)) {
				c++;
			}
			else if (c%2==0) {
				b++;
			}
			else {
				b--;
			}
		}
	}
	rep(i, h) {
		rep(j, w-1) {
			cout << vec[i][j] << " ";
		}
		cout << vec[i][w-1] << endl;
	}
}*/
