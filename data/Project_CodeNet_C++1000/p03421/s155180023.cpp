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

template<class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } else return; }
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) { o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o; }
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) { o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o; }
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) { o << "{" << obj.first << ", " << obj.second << "}"; return o; }
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
void print(void) { cout << endl; }
template <class Head> void print(Head&& head) { cout << head; print(); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << " "; print(forward<Tail>(tail)...); }
template <class T> void chmax(T& a, const T b) { a = max<T>(a, b); }
template <class T> void chmin(T& a, const T b) { a = min<T>(a, b); }
void YN(bool flg) { cout << ((flg) ? "YES" : "NO") << endl; }
void Yn(bool flg) { cout << ((flg) ? "Yes" : "No") << endl; }
void yn(bool flg) { cout << ((flg) ? "yes" : "no") << endl; }

int main() {
	ll N, A, B; cin >> N >> A >> B;
	corner(A + B - 1 > N, -1);
	corner(A*B < N, -1);

	if(A >= B){
		int p = 1;
		int M = N;
		V<V<int>> node(A);
		for(int i = 0; i < A; ++i){
			node[i].push_back(p);
			p++;
			M--;
			for(int j = 1; j < B && M > A - (i + 1); ++j){
				node[i].push_back(p);
				p++;
				M--;
			}
			sort(ALL(node[i]), greater<int>());
		}
		for(auto u:node){
			for(auto v:u){
				cout << v << " ";
			}
		}
		cout << endl;
	}
	else {
		int p = N;
		int M = N;
		V<V<int>> node(B);
		for (int i = 0; i < B; ++i) {
			node[i].push_back(p);
			p--;
			M--;
			for (int j = 1; j < A && M > B - (i + 1); ++j) {
				node[i].push_back(p);
				p--;
				M--;
			}
			sort(ALL(node[i]));
		}
		for (auto u : node) {
			for (auto v : u) {
				cout << v << " ";
			}
		}
		cout << endl;
	}

	return 0;
}

