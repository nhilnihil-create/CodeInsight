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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

void normalize(vector<P>& res) {
    if(res.size() > 1) {
        if(res[res.size() - 2].fr == res[res.size() - 1].fr) {
            res[res.size() - 2].sc += res[res.size() - 1].sc;
            res.pop_back();
        }
    }
}

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int ok = n, ng = 0;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        vector<pair<int, int>> res;
        res.push_back(make_pair(0, a[0]));
        for(int i = 1; i < n; ++i) {
            if(a[i - 1] < a[i]) {
                res.push_back(make_pair(0, a[i] - a[i - 1]));
            } else {
                int cnt = 0;
                while(cnt + res.back().sc <= a[i - 1] - a[i]) {
                    cnt += res.back().sc;
                    res.pop_back();
                }
                auto now = res.back();
                cnt += now.sc;
                res.pop_back();
                int alp = now.fr, co = a[i] - (a[i - 1] - cnt); 
                if(alp != mid - 1) {
                    if(co - 1 > 0) res.push_back(make_pair(alp, co - 1));
                    res.push_back(make_pair(alp + 1, 1));
                } else {
                    if(res.size() == 0) {
                        ng = mid;
                        break;
                    } else {
                        now = res.back();
                        res.pop_back();
                        if(now.sc - 1 > 0) res.push_back(make_pair(now.fr, now.sc - 1));
                        res.push_back(make_pair(now.fr + 1, 1));
                        normalize(res);
                        res.push_back(make_pair(0, co));
                    }
                }
            }
            normalize(res);
            if(i == n - 1) ok = mid;
        }
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
