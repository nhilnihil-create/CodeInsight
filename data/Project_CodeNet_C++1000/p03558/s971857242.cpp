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
const ll MOD2 = 998244353;
const ll LLINF = (ll)1e18;
const ll INTINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}
template <class T> void chmin(T& a, const T b){a=min<T>(a,b);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}

#include <bits/stdc++.h>
using namespace std;

//Dijkstra
template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost; 
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for(int i = 0; i < N; ++i) cost[i] = inf;

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			T v = pq.top().first;
			int from = pq.top().second;
			pq.pop();
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

//verify 

int main() {
	ll K; cin >> K;
	Dijkstra<ll> dijk(K,INTINF);
	REP(i,K) dijk.make_edge(i,(i+1)%K,1);
	REP(i,K) dijk.make_edge(i,(i*10)%K,0);
	dijk.solve(1);
	cout << dijk.cost[0] + 1 << endl;
	return 0;
}
