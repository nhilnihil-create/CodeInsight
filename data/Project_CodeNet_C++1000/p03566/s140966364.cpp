#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<double> t(n), v(n);
    int T = 0;
    rep(i, n){
        cin >> t[i];
        T += t[i];
    }
    rep(i, n) cin >> v[i];

    const int INF = 1e9;
    vector<double> maxv(2*T+1, INF);

    int now = 0;
    rep(i, n){
        rep(j, t[i]){
            int t1 = now + 2*j;
            int t2 = now + 2*j + 1;
            maxv[t1] = min(maxv[t1], v[i]);
            maxv[t2] = min(maxv[t2], v[i]);
        }
        now += t[i] * 2;
        maxv[now] = min(maxv[now], v[i]);
    }

    maxv[0] = 0;
    maxv[2*T] = 0;

    for(int i=1; i<=2*T; i++){
        maxv[i] = min(maxv[i], maxv[i-1]+0.5);
    }

    for(int i=2*T-1; i>=0; i--){
        maxv[i] = min(maxv[i], maxv[i+1]+0.5);
    }

    double ans = 0;
    for(int i=0; i<=2*T; i++){
        ans += 0.25 * (maxv[i] + maxv[i+1]);
    }

    cout << fixed << setprecision(9) << ans << endl;
}