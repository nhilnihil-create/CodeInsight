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

bool cmp(P a, P b) {
    if(a.fi!=b.fi) return a.fi<b.fi;
    else return a.se<b.se;
}

signed main() {
    int n;
    cin >> n;
    V(P) red(n), blue(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        red[i] = P(a, b);
    }
    rep(i, n) {
        int c, d;
        cin >> c >> d;
        blue[i] = P(c, d);
    }
    sort(ALL(red), cmp); sort(ALL(blue), cmp);

    V(bool) done(n, false);
    int res = 0;
    rep(i, n) {
        int mj = 0;
        rep(j, n) {
            if(done[j]) continue;
            if(red[j].fi<blue[i].fi && red[j].se<blue[i].se) {
                if(red[mj].fi<blue[i].fi && red[mj].se<blue[i].se && !done[mj]) {
                    if(red[j].se > red[mj].se) mj = j;
                } else mj = j;
            }
        }
        if(red[mj].fi<blue[i].fi && red[mj].se<blue[i].se && !done[mj]) {
            res++;
            done[mj] = true;
        }
    }

    cout << res << endl;
    
    return 0;
}