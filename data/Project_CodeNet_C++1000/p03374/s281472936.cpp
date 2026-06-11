#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(ll i=n;i<N;i++)
#define RREP(i,n,N) for(ll i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf = 1e9+7;

ll N;
ll C;
ll x[100010];
ll v[100010];
ll sum[100010];
ll rsum[100010];
ll y[100010];
ll d[100010];

ll solve(){
    sum[0] = v[0];
    REP(i,1,N){
        sum[i]=sum[i-1]+v[i];
    }
    REP(i, 0, N) y[i] = C - x[i];
    rsum[N - 1] = v[N - 1];
    RREP(i, 0, N - 1) rsum[i] = rsum[i + 1] + v[i];

    d[N - 1] = rsum[N - 1] - y[N - 1];
    RREP(i, 0, N - 1) {
        d[i] = rsum[i] - y[i];
        d[i] = max(d[i], d[i + 1]);
    }


    ll ans = 0;
    REP(i, 0, N) {
        ll sm = 0;

        sm -= x[i];
        sm += sum[i];
        ans = max(ans, sm);

        sm -= x[i];

        if (i < N - 1) sm += d[i + 1];

        ans = max(ans, sm);
    }

    return ans;
}

int main() {
    cin>>N>>C;
    ll ans = 0;
    REP(i,0,N) {
        cin >> x[i] >> v[i];
    }
    ans = solve();
    REP(i,0,N) x[i] = C - x[i];
    reverse(x,x+N);
    reverse(v,v+N);
    ans = max(ans,solve());
    p(ans);
    return 0;
}