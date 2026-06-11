# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        (wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)
# pragma warning(disable:4996)

int n;
int g[1010][1010];
int main() {
	cin >> n;
	int sum = 0;
	bool flg = false;
	if (n == 1) {
		cout << "Yes" << endl;
		cout << "2\n1 1\n1 1" << endl;
		return 0;
	}
	int num = -1;
	for (int i = 1; sum + i <= n; i++) {
		sum += i;
		if (sum == n) {
			flg = true;
			num = i + 1;
		}
	}
	if (flg) {
		cout << "Yes" << endl;
		cout << num << endl;
		int k = 1;
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				if (i == j)continue;
				if (g[i][j] == 0)g[i][j] = g[j][i] = k++;
			}
		}
		for (int i = 1; i <= num; i++) {
			cout << num - 1;
			for (int j = 1; j <= num; j++) {
				if (i == j)continue;
				cout << " " << g[i][j];
			}
			cout << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
	//system("pause");
}