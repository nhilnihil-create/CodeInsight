#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

ll func(int k) {
    if (k==0) return 5;
    if (k==1) return 0;
    return 2;
}

int main() {
    int N; cin >> N;
    ll X; cin >> X;
    vector<ll> x(N);
    REP(i,N) cin >> x[i];
    vector<ll> x_sum(N+1,0);
    REP(i,N) x_sum[i+1] = x_sum[i] + x[i];
    ll ans = INF;
    FOR(i,1,N+1) {
        ll tmp = 0;
        int cnt = 0;
        for(int j=N;j>=1;j-=i) {
            tmp += func(cnt) * x_sum[j];
            if(tmp > (ll)1e17) break;
            cnt ++;
        }
        ans = min(ans, tmp + ((ll)N+i)*X);
    }
    cout << ans << endl;
}