#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vvi G(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    function<int(int, int)> dfs = [&](int i, int j) {
        int res = 0, rres = -1;
        for(int ne:G[i]) {
            if(ne == j) continue;
            int x = dfs(ne, i);
            if(x > res) {
                rres = res;
                res = x; 
            } else if(x > rres) {
                rres = x;
            }
        }
        chmax(ans, res+rres+1);
        return res+1;
    };
    dfs(0, -1);

    cout << (ans%3 == 2?"Second":"First") << endl;
}
