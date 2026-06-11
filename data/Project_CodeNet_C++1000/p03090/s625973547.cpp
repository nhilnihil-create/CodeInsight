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
    V(P) res;
    if(N%2) {
        rep(i, N-2) {
            FOR(j, i+1, N-1) {
                if(i+j+2==N) continue;
                res.pb(P(i+1, j+1));
            }
        }
        rep(i, N-1) {
            res.pb(P(i+1, N));
        }
    } else {
        rep(i, N-1) {
            FOR(j, i+1, N) {
                if(i+j+2==N+1) continue;
                res.pb(P(i+1, j+1));
            }
        }
    }

    cout << res.size() << endl;
    rep(i, res.size()) cout << res[i].fi << " " << res[i].se << endl;

    /*vi ch(N, 0);
    rep(i, res.size()) {
        ch[res[i].fi-1] += res[i].se;
        ch[res[i].se-1] += res[i].fi;
    }

    rep(i, N) cout << ch[i] << " ";
    cout << endl;*/

    return 0;
}