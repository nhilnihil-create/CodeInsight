#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int n;
vector<int> d;
bool ok = false;
void dfs(int k, vector<int> vec, int val) {
    if (k==n) {
        ok = true;
    } else {
        rep(i, 2) {
            vector<int> a = vec;
            int next = abs(24*i-d[k+1]) % 24;
            if (next==12 && i==1) continue;
            a.push_back(next);
            sort(all(a));
            bool check = true;
            rep(i, sz(a)-1) {
                if (min(a[i+1]-a[i],24-(a[i+1]-a[i]))<val) {
                    check = false;
                    break;
                }
            }
            if (min(abs(a.back()-a.front()),24-(a.back()-a.front()))<val) check = false;
            if (check) {
                dfs(k+1, a, val);
            }
        }
    }
}

int main() {
    cin >> n;
    d.resize(n+1);
    d[0] = 0;
    rep(i, n) cin >> d[i+1];
    map<int, int> mp;
    rep(i, n+1) mp[d[i]]++;
    for(const auto& m: mp) {
        // cout << m.fi << " " << m.se << endl;
        if ((m.fi==12||m.fi==0) && m.se>=2) {
            cout << 0 << endl;
            return 0;
        }
        if (m.se>2) {
            cout << 0 << endl;
            return 0;
        }
    }
    if (sz(d) > 12) {
        cout << 1 << endl;
        return 0;
    }
    for(int i=12; i>=0; i--) {
        ok = false;
        vector<int> vec = {0};
        dfs(0, vec, i);
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}