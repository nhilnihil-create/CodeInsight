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
const ll INF = mod * mod;
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
//#define int long long

void solve() {
    string s; cin >> s;
    int n = s.size();
    //必要条件から攻めよ
    if(s[0] == '0' || s[n - 1] == '1' || s[n - 2] == '0') {
        cout << -1 << endl;
        return;
    }
    rep(i, n) {
        if(i == n - 1) continue;
        if(s[i] != s[n - 2 - i]) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> vec;
    rep(i, n) {
        if(s[i] == '1') {
            vec.push_back(i + 1);
        }
    }
    int m = vec.size();
    int i = 1, j = 2;
    int cnt = 1;
    rep(k, m) {
        while(vec[k] > cnt) {
            cout << i << " " << j << endl;
            j ++;
            cnt ++;
        }
        cout << i << " " << j << endl;
        cnt ++;
        i = j; j = j + 1;
    }
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