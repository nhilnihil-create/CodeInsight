#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll>a(m, 0);
    REP(i, m) cin >> a[i];

    sort(ALL(a));

    vector<ll> dist(m-1, 0);

    REP(i, m-1){
        dist[i] = a[i+1] - a[i];
    }

    sort(ALL(dist), greater<int>());

    ll ans = 0;

    FOR(i, n-1, m-1){
        ans += dist[i];
    }

    cout << ans << endl;


}
