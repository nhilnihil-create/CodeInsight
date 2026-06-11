#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(long long i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(long long i=int(n);i>0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+5  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
using PPI = pair<P, int>;
//ll const mod=998244353;
ll const mod = 1e9 + 7;
const ll MAX = 1000005;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vd = vector<double>;
using vs = vector<string>;
using vp = vector<P>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvd = vector<vector<double>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
using vvb = vector<vector<bool>>;
template <typename T>
bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template <typename T>
bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }


int main() {
    int n, C;
    cin >> n >> C;
    vvi d(C, vi(C));
    vvi c(n, vi(n));
    rep(i, C)rep(j, C) {
        cin >> d[i][j];
    }
    rep(i, n)rep(j, n) {
        cin >> c[i][j];
        c[i][j]--;
    }

    vvi a(3);
    rep(i, n)rep(j, n) {
        a[(i + j + 2) % 3].push_back(c[i][j]);
    }
    P res[3][3];
    rep(i, 3)rep(j, 3)res[i][j].fs = INF;
    rep(i, C) {
        int tmp = 0;
        for (auto x : a[0]) {
            tmp += d[x][i];
        }
        P s;
        s.first = tmp, s.second = i;
        rep(j, 3) {
            if (s < res[0][j]) {
                swap(s, res[0][j]);
            }
        }

        tmp = 0;
        for (auto x : a[1]) {
            tmp += d[x][i];
        }
        s.first = tmp, s.second = i;
        rep(j, 3) {
            if (s.fs < res[1][j].fs) {
                swap(s, res[1][j]);
            }
        }

        tmp = 0;
        for (auto x : a[2]) {
            tmp += d[x][i];
        }
        s.fs = tmp, s.sc = i;
        rep(j, 3) {
            if (s.fs < res[2][j].fs) {
                swap(s, res[2][j]);
            }
        }
    }
    int ans = INF;
    rep(i, 3)rep(j, 3)rep(k,3) {
        if (res[0][i].sc == res[1][j].sc || res[1][j].sc == res[2][k].sc||res[0][i].sc==res[2][k].sc)continue;
        chmin(ans, res[0][i].fs + res[1][j].fs + res[2][k].fs);
    }
    cout << ans<< endl;
    return 0;
}