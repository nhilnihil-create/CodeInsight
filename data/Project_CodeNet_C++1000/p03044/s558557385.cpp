#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
template <class T, class U>ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
template <class T>ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	rep(i, v.size()) {
		if (i) os << ",";
		os << v[i];
	}
	os << "}";
	return os;
}
template <class T, class U>istream& operator>>(istream& is, pair<T, U>& p) {
	is >> p.first >>p.second ;
	return is;
}
template <class T>istream& operator>>(istream& is,  vector<T>& v) {
	rep(i, v.size()) {
		is >> v[i];
	}
	return is;
}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n;
	int ans=0;
	cin >>n;
	int u,v,w;
	vector<vector<pair<int, int>>> path(n);
	vector<int> has(n, -1);
	has[0] = 0;
	rep(i, n-1) { cin >> u >> v >> w;
		u--;
		v--;
		path[u].eb(v, w);
		path[v].eb(u, w);
	}
	deque<int> q;
	int at;
	
	
		q.pb(0);
		while (!q.empty()) {
			at = q.front();
			q.pop_front();

			repi(itr, path[at]) {
				if (has[itr->F] != -1) continue;
				if (itr->S % 2 == 0) {
					has[itr->F] = has[at];
				} else {
					has[itr->F] = (has[at] + 1) % 2;
				}
				q.push_back(itr->F);
			}
	
	}
	//clog << has << endl;
	rep(i, n) { cout << has[i] << endl; }
}