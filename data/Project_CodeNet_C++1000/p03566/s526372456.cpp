#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i = (n)-1; i >=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i =(b)-1; i >= a; i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
const double inf = 1e9;
int main(){
    int n; cin >> n;
    vector<double> t(n),v(n);
    rep(i,n) cin >> t[i];
    rep(i,n) cin >> v[i];
    double ts = 0.0;
    rep(i,n) ts += t[i];
    vector<double> mv(2*ts + 1, inf);
    double now = 0.0;
    rep(i,n){
        rep(j, t[i]){
            double tl = now + 2*j;
            double tr = now + 2*j + 1;
            mv[tl] = min(mv[tl], v[i]);
            mv[tr] = min(mv[tr], v[i]);
        }
        now += 2*t[i];
        mv[now] = min(mv[now], v[i]);
    }
    mv[0] = mv[2*ts] = 0;
    rep(i, 2*ts + 1) mv[i+1] = min(mv[i+1], mv[i] + 0.5);
    rrep(i, 2*ts + 1) mv[i] = min(mv[i], mv[i+1] + 0.5);
    double ans = 0.0;
    rep(i, 2*ts + 1) ans += (mv[i] + mv[i+1]) / 4.0;
    printf("%.10f\n", ans);
}