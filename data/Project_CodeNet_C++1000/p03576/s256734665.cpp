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

bool cmp_x(P a, P b) {
    if(a.fi != b.fi) return a.fi < b.fi;
    else return a.se < b.se;
}

bool cmp_y(P a, P b) {
    if(a.se != b.se) return a.se < b.se;
    else return a.fi < b.fi;
}

signed main() {
    int N, K;
    cin >> N >> K;
    V(P) p(N), xf(N), yf(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        P t = P(x, y);
        p[i]=t; xf[i]=t; yf[i]=t;
    }
    sort(ALL(xf), cmp_x); sort(ALL(yf), cmp_y);

    int res = 5e18;
    for(int xi=0; xi<N-1; xi++) {
        for(int xj=xi+1; xj<N; xj++) {
            for(int yi=0; yi<N-1; yi++) {
                for(int yj=yi+1; yj<N; yj++) {
                    int mix=xf[xi].fi, max=xf[xj].fi;
                    int miy=yf[yi].se, may=yf[yj].se;

                    int cnt = 0;
                    rep(i, N) {
                        int px=p[i].fi, py=p[i].se;
                        if((mix<=px && max>=px) && (miy<=py && may>=py)) cnt++;
                    }

                    if(cnt>=K) {
                        int s = (max-mix)*(may-miy);
                        res = min(res, s);
                    }
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}