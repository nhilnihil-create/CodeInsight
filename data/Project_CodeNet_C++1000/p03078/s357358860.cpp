#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
typedef long long ll;
typedef long double ld;
typedef unsigned long long int ull;
const ll INF = 1LL << 60;
const int inf = 1 << 25;
ll n, m, k, y, x, d, w = 1, num, sum, ans = 0; string s;
vector<vector<int>> Gragh;
int main(void) {
	cin >> x >> y >> d >> k;
	vector<ll> a(x), b(y), c(d),D,e;
	rep(i, x) cin >> a[i];
	rep(i, y)cin >> b[i];
	rep(i, d) cin >> c[i];
	sort(RALL(a)); sort(RALL(b)); sort(RALL(c));
	rep(i, x) {
		rep(j, y) {
			D.push_back(a[i] + b[j]);
		}
	}sort(RALL(D));
	rep(i, min(k,x*y)) {
		rep(j, d) {
			e.push_back(D[i] + c[j]);
		}
	}sort(RALL(e));
	rep(i, k) cout << e[i] << endl;
}