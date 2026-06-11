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

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define ALL(obj) (obj).begin(),(obj).end()

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template<class T> void corner(bool flg, T hoge) {
	if (flg) {
		cout << hoge << endl;
		exit(0);
	}
	else return;
}

template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {
	o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;
}

template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {
	o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;
}

template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {
	o << "{" << obj.first << ", " << obj.second << "}"; return o;
}

template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

void print(void) {
	cout << endl;
}

template <class Head> void print(Head&& head) {
	cout << head;
	print();
}

template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
	cout << head << " ";
	print(forward<Tail>(tail)...);
}

void YN(bool flg) {
	cout << ((flg) ? "YES" : "NO") << endl;
}

void Yn(bool flg) {
	cout << ((flg) ? "Yes" : "No") << endl;
}

void yn(bool flg) {
	cout << ((flg) ? "yes" : "no") << endl;
}

int main() {
	int N; cin >> N;
	V<int> u(N+2,0);
	V<double> v(N+2,0);
	FOR(i,1,N+1) cin >> u[i];
	FOR(i,1,N+1) cin >> v[i];
	int MAX_t = 100 * 200 * 2 + 2, SUM_t = 0;
	V<double> dp(MAX_t, 1e15);
	REP(i,N+2){
		for (int t = SUM_t,j = 0; 0 <= t; --t, ++j) dp[t] = min(dp[t], v[i] + j*0.5);
		for (int t = SUM_t; t < SUM_t + 2*u[i]; ++t) dp[t] = min(dp[t], v[i]);
		for (int t = SUM_t + 2*u[i],j = 0; t < MAX_t; ++t, ++j) dp[t] = min(dp[t], v[i] + j*0.5);
		SUM_t += 2*u[i];
	}
	printf("%.10f", 0.5*accumulate(dp.begin(), dp.begin() + SUM_t, 0.));
	
	return 0;
}

