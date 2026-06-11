#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template <class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } }
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) { o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o; }
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) { o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o; }
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) { o << "{" << obj.first << ", " << obj.second << "}"; return o; }
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
void print(void) { cout << endl; }
template <class Head> void print(Head&& head) { cout << head; print(); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << " "; print(forward<Tail>(tail)...); }
void YN(bool flg) { cout << ((flg) ? "YES" : "NO") << endl; }
void Yn(bool flg) { cout << ((flg) ? "Yes" : "No") << endl; }
void yn(bool flg) { cout << ((flg) ? "yes" : "no") << endl; }

//Repeat Square Method x^n MOD 
long long RSM(long long x, long long n, long long MOD) {
	long long y = 1;
	for (; n > 0; n >>= 1, (x *= x) %= MOD) if (n & 1) (y *= x) %= MOD;
	return y;
}

int main() {
	ll N; cin >> N;
	V<ll> A(N + 1,0);
	FOR(i, 1, N + 1) cin >> A[i];
	V<ll> P(N + 1,0);
	FOR(i, 1, N + 1) P[i] = RSM(i, MOD - 2, MOD);
	FOR(i, 1, N + 1) (P[i] += P[i - 1]) %= MOD;
	V<ll> C(N + 1);
	FOR(i, 1, N + 1) C[i] = (P[N - (i - 1)] + (P[i] - P[1]) + MOD)%MOD;
	ll ans = 0;
	FOR(i, 1, N + 1) (ans += (C[i] * A[i]) % MOD) %= MOD;
	FOR(i, 1, N + 1) (ans *= i) %= MOD;
	cout << ans << endl;
}