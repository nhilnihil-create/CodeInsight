#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, tmp=0;
vector<ll> t, v;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll T;
        cin >> T;
        t.push_back(T);
        tmp += T;
    }
    for(int i=0;i<N;i++) {
        ll V;
        cin >> V;
        v.push_back(V);
    }
    ll nowt = 0;
    vector<double> vmax(2*tmp+1, 1000.0);
    vmax[0] = vmax[2*tmp] = 0.0;
    for(int i=0;i<N;i++) {
        if(i==0) vmax[nowt] = 0.0;
        else vmax[nowt] = v[i-1];
        for(int j=0;j<t[i];j++) {
            ll t1 = nowt + 2*j;
            ll t2 = nowt + 2*j + 1;
            vmax[t1] = min(vmax[t1], (double)v[i]);
            vmax[t2] = min(vmax[t2], (double)v[i]);
        }
        nowt += 2*t[i];
    }
    for(int i=0;i<2*tmp;i++) {
        vmax[i+1] = min(vmax[i+1], vmax[i]+0.5);
    }
    for(int i=2*tmp-1;i>=0;i--) {
        vmax[i] = min(vmax[i], vmax[i+1]+0.5);
    }
    double ans = 0.0;
    for(int i=0;i<2*tmp;i++) {
        ans += (vmax[i]+vmax[i+1]) / 4.0;
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}