#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define sort(s) sort(s.begin(),s.end())
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<int>>
constexpr auto mod = 1000000007;


//2のn乗を求めるよ！！！
int ni(int n) {
	if (n == 0)return 1;
	int x = ni(n / 2);
	x *= x;
	if (n % 2 == 1)x *= 2;
	return x;
}

//フィボナッチ数列のx番目を求めるよ！
int f(int x, vector<int> s) {
	if (x == 0)return 0;
	if (x == 1)return 1;
	if (s[x] != 0)return s[x];
	s[x] = f(x - 1, s) + f(x - 2, s);
	return s[x];
}

//aとｂの最大公約数を求めるよ！
llint gcd(llint a, llint b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}



// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// mod. m での a の逆元 a^{-1} を計算するよ！
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}


//aCbをmod.mで割った余りを求める
ll int c(ll int a, ll int b, ll int m) {
	ll int ans = 1;
	for (ll int i = 0; i < b; i++) {
		ans *= a - i;
		ans %= m;
	}
	for (ll int i = 1; i <= b; i++) {
		ans *= modinv(i, m);
		ans %= m;
	}
	return ans;
}

//m進数のn桁を全列挙やで
void dfs(int m, int n) {

	stack<string> st;
	st.push("");
	while (!st.empty()) {
		string now = st.top();
		st.pop();
		if (now.size() == n) {
			cout << now << endl;
		}
		else {
			for (int i = m - 1; i >= 0; i--) {
				string next = now + to_string(i);
				st.push(next);
			}
		}
	}
}

int main() {
	int n;
	ll int ans = 0;
	cin >> n;
	llint Asum = 0, Bsum = 0, x = 0;
	hei(int) a(n), b(n),s(n,0);
	rep(i, 0, n) {
		cin >> a[i];
		Asum += a[i];
	}
	rep(i, 0, n) {
		int s;
		cin >> s;
		Bsum += s;
		b[i] = a[i] - s;
	}
	if (Bsum > Asum)ans = -1;
	else {
		rep(i, 0, n) {
			if (b[i] < 0)x += -1 * b[i], ans++;
			else s[i] = b[i];
		}
		sort(s);
		for (int i = n - 1;; i--) {
			if (x < 1)break;
			x -= s[i];
			ans++;
		}

	}
	cout << ans << endl;

	return 0;
}