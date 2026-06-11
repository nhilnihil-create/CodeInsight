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
const ll mod = 1000000007;
const ll INF = 1e+12;
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
typedef vector<int> vec;
typedef vector<string> svec;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int long long

//ある量を決めるとどうすべきかがgreedyに決まる
//探索すべきものを絞る

//ちょうどを以上にしても大丈夫
//x種類選んだ状態とx+1種類選んだ状態との間の差分をいかに素早く更新できるようなデータの持ち方を工夫する

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> s(n);
    rep(i, n) {
        int t, d; cin >> t >> d;
        t --; //配列のindexにとる時はその範囲に要注意！
        s[t].push_back(d);
    }
    for(auto &v : s) {
        sort(all(v), greater<int>());
        if(v.empty()) v.push_back(-INF); //番兵
    }

    sort(all(s), [&](vector<int> a, vector<int> b) {return a[0] > b[0];});
    
    priority_queue<int> pque;
    int cur = 0;
    rep(i, k) {
        cur += s[i][0];
        for(int j = 1; j < (int)s[i].size(); j++) {
            pque.push(s[i][j]);
        }
    }
    Rep(i, k, n) {
        rep(j, (int)s[i].size()) {
            pque.push(s[i][j]);
        }
    }

    int res = cur + k * k;
    for(int x = k - 1; x >= 1; x--) { //何度も同じ計算をしない（例　累積和）
        int v = s[x][0];
        int w = pque.top();
        if(v < w) {
            cur += w; pque.pop();
            cur -= v; pque.push(v);
        }
        res = max(res, cur + x * x);
    }
    cout << res << endl;
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