#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

bool cmp(const string &s, const string &t) {
    int n = s.length();
    int m = t.length();
    if (n < m) return true;
    else if (n > m) return false;
    rep(i,n) {
        if (s[i] < t[i]) return true;
        else if (s[i] > t[i]) return false;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int n,m; cin>>n>>m;
    vector<int> a(m);
    rep(i,m) cin>>a[i];
    
    const int costs[10] = {INF,2,5,5,4,5,6,3,7,6};
    vector<string> dp(n+1, "$");
    dp[0] = "";
    for (int i = 1; i <= n; ++i) {
        for (auto &&e: a) {
            int cost = costs[e];
            if (i-cost < 0) continue;
            if (dp[i-cost] == "$") continue;
            string t = dp[i-cost];
            char c = e+'0';
            t.push_back(c);
            if (cmp(dp[i], t)) dp[i] = t;
            /*
            cout << "t = " << t << '\n';
            cout << "dp[" << i << "] = " << dp[i] << '\n';
            */
        }
    }

    cout << dp[n] << '\n';

    return 0;
}