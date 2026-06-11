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

template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}

int main() {
	int N; cin >> N;
	V<ll> x(N),y(N);
	REP(i,N) cin >> x[i] >> y[i];
	ll prt = abs(x[0]+y[0])%2;
	REP(i,N) corner((abs(x[i]+y[i])%2)!=prt,-1);
	int m = 31+!prt;
	V<ll> d;
	REP(i,31) d.push_back(1LL<<i);
	if(!prt)d.push_back(1);

	cout << m << endl;
	REP(i,m) cout << d[i] << " "; cout << endl;

	REP(i,N){
		ll u = x[i]+y[i];
		ll v = x[i]-y[i];
		ll ub=(u+(1<<31)-prt)/2;
		ll vb=(v+(1<<31)-prt)/2;
		string ans;
		REP(i,31) {
			char c;
			if( !(ub&(1<<i)) && !(vb&(1<<i)) ) c = 'L';
			if( (ub&(1<<i)) && (vb&(1<<i)) ) c = 'R';
			if( !(ub&(1<<i)) && (vb&(1<<i)) ) c = 'D';
			if( (ub&(1<<i)) && !(vb&(1<<i)) ) c = 'U';
			ans.push_back(c);
		}
		if(!prt)ans.push_back('L');
		cout << ans << endl;
	}



}

