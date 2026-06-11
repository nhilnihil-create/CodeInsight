#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define ALL(x) (x).begin(), (x).end()
int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1};
constexpr int INF=1<<30;
constexpr ll LINF=1LL<<60; 
constexpr ll mod=1e9+7;
void flush() {cout<<flush;}
template<class T>vector<T> vec(int len, T elem) { return vector<T>(len, elem); } // auto dp = vec(52, vec(103, vec(103, INF)));
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T>inline int popcount(T a) {return __builtin_popcount(a);}
template<class T>inline T emod(T a, T p) { return (a%p + p) % p;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << '\n'; for (auto v : vec) os << v << ' '; os << '\n'; return os;}
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
struct MyIO {
    MyIO(){
        cin.tie(0); 
        ios::sync_with_stdio(false); 
        cout << fixed << setprecision(15);
    }
} IO_OI;
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
//-------------------
int main() {
	int n,q;cin>>n>>q;
	string s;cin>>s;
	vector<char> t(q);
	vector<char> d(q);
	rep(i,q) cin >> t[i] >> d[i];
	int a[2];
	{ 
		int left = -1, right = n;
		while(left+1 < right) {
			int mid = (left+right)/2;
			int place = mid;
			bool ok = false;
			rep(i,q) {
				if(s[place]==t[i]) {
					if(d[i]=='R') {
						place++;
						if(place==n) {
							break;
						}
					} else {
						place--;
						if(place==-1)  {
							ok = true;
							break;
						}
					}
				}
			}
			if(ok) left = mid;
			else right = mid;
		}
		a[0] = left;
	}
	{ 
		int left = -1, right = n;
		while(left+1 < right) {
			int mid = (left+right)/2;
			int place = mid;
			bool ok = false;
			rep(i,q) {
				if(s[place]==t[i]) {
					if(d[i]=='R') {
						place++;
						if(place==n) {
							ok = true;
							break;
						}
					} else {
						place--;
						if(place==-1)  {
							break;
						}
					}
				}
			}
			if(ok) right = mid;
			else left = mid;
		}
		a[1] = right;
	}
	cout << a[1] - a[0] - 1 << endl;
}