#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cout << #x << " = " << (x) << endl;
using Graph = vector<vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int long long

template <class Abel> struct BIT {
private:
	vector<Abel> node; int n;
    Abel UNITY_SUM = 0; //to be set
public:
	BIT(int n_) {
		n = n_; node.resize(n, UNITY_SUM);
	}
	//0-indexed
	void add(int a, Abel w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	Abel sum(int a) {
		Abel ret = UNITY_SUM;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	Abel sum(int a, int b) {
		return sum(b) - sum(a);
	}
    //debug
    void print() {
        for(int i = 0; i < n; ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

//BITで和は分かるから、それをどう使うか
//平均がaなら、全部-aして、合計が0で考えるとok
//累積和からBITからの転倒数
//和が０となるものを考えれば良いように値を加工する
//区間長に依存しない

void solve() {
	int n; cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i];
    int ok = 0, ng = 1LL<<32;

    const int geta = n + 1;
    while(ng - ok > 1) {
		int mid = (ng + ok) / 2;
	    BIT<ll> bit(2 * n + 10);
        ll num = 0;
        int sum = 0;
        bit.add(sum + geta, 1);
        rep(i, n) {
            int val;
            if(a[i] >= mid) val = 1;
            else val = -1;
            sum += val; //sumはマイナスもありうる -> getaをたして、マイナスをプラスにして扱う
            //転倒数を求めるパート
            num += bit.sum(0, sum + geta + 1); //今まで出た自分以下の数の個数
            bit.add(sum + geta, 1);
        }
        if(num >= ((n + 1) * n / 2 + 1) / 2 ) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}