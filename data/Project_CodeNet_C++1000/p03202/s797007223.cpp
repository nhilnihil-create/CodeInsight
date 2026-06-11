#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

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
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
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

int main() {
	int N; cin >> N;
	V<ll> A(N); REP(i, N) cin >> A[i];
	corner(N==1,1);
	for(int i = 0; i < N - 1; ++i){
		if(A[i] >= A[i+1]) break;
		corner(i==N-2,1);
	}

	ll ok = N,ng = 1,md;
	while(ok-ng>1){
		md = (ok+ng)/2;
		map<ll,ll> mp,mp2;
		int flg = 1;
		for(int i = 1; i < N; ++i){
		
			if(A[i-1]<A[i]) continue;
		
			ll j = A[i];
			if(mp2.count(j)) j = mp2[j];

			if(j==0){
				flg = 0;
				break;
			}
			
			mp[j]++;
			if(mp[j] == md - 1){
				if(mp2.count(j-1)==0) mp2[j]=j-1;
				else mp2[j] = mp2[j-1];
			}
			auto itr = mp.upper_bound(j);
			mp.erase(itr,mp.end());
			auto itr2 = mp2.upper_bound(j);
			mp2.erase(itr2,mp2.end());
		}
		(flg?ok:ng) = md;
	}
	cout << ok << endl;
	return 0;
}
