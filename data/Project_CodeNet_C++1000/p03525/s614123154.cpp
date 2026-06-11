#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

signed main() {
    int N;
    cin >> N;
    vi T(N+1);
    rep(i, N) cin >> T[i];
    T[N] = 0;
    SORT(T);

    int res = INF;
    int lp=0, rp=0;
    FOR(i, 1, N+1) {
        if(i%2) {
            res = min(res, T[i]-lp);
            lp = T[i];
        } else {
            res = min(res, T[i]-rp);
            rp = T[i];
        }
        res = min(res, (12-lp)+(12-rp));
    }

    cout << res << endl;

    return 0;
}