#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#define NDEBUG
#endif
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T,U>& p) { os << '(' << p.first << ' ' << p.second << ')'; return os; }

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#ifdef LOCAL111
	#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
	template<typename T> void dpite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
#else
	#define DEBUG(x) true
	template<typename T> void dpite(T a, T b){ return; }
#endif
#define F first
#define S second
#define SNP string::npos
#define WRC(hoge) cout << "Case #" << (hoge)+1 << ": "
template<typename T> void pite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;

void ios_init(){
	//cout.setf(ios::fixed);
	//cout.precision(12);
#ifdef LOCAL111
	return;
#endif
	ios::sync_with_stdio(false); cin.tie(0);
}

int main()
{
	ios_init();
	int n;
	while(cin >> n) {
		vector<int> a(n);
		REP(i, n) cin >> a[i];
		bool f = true;
		REP(i, n) {
			if(a[i] != 0) {
				f = false;
			}
		}
		if(f) {
			cout << 0 << endl;
			continue;
		}
		auto mi = min_element(ALL(a));
		auto ma = max_element(ALL(a));
		vector<P> ans;
		if(abs(*ma) > abs(*mi)) {
			a[0] += *ma * 2;
			REP(_, 2) ans.emplace_back(ma - a.begin() + 1, 1);
			REP(i, n-1) {
				a[i+1] += a[i] * 2;
				ans.emplace_back(i+1, i+2);
				ans.emplace_back(i+1, i+2);
			}
		} else {
			a[n-1] += *mi * 2;
			REP(_, 2) ans.emplace_back(mi - a.begin() + 1, n);
			RREP(i, n-1) {
				a[i] += a[i+1] * 2;
				ans.emplace_back(i+2, i+1);
				ans.emplace_back(i+2, i+1);
			}
		}
		dpite(ALL(a));
		cout << SZ(ans) << endl;
		REP(i, SZ(ans)) {
			cout << ans[i].F << ' ' << ans[i].S << endl;
		}
	}
	return 0;
}
