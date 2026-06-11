#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

int main() {
    ll N,C;
    cin >> N >> C;
    vector<Pll> sushi(N+2, Pll(0, 0));
    reppp(i, 1, N+1) cin >> sushi[i].first >> sushi[i].second;
    sushi[N+1].first = C;
    sushi[N+1].second = 0;

    vector<ll> asc(N+2, 0), asc_max(N+2, INT_MIN), desc(N+2, 0), desc_max(N+2, INT_MIN);
    reppp(i, 1, N+1){
        asc[i] = asc[i-1] + sushi[i].second - (sushi[i].first - sushi[i-1].first);
        asc_max[i] = max(asc[i], asc_max[i-1]);
    }
    asc[N+1] = asc[N];
    asc_max[N+1] = asc_max[N];
    for(int i=N;i>=1;i--){
        desc[i] = desc[i+1] + sushi[i].second - (sushi[i+1].first - sushi[i].first);
        desc_max[i] = max(desc[i], desc_max[i+1]);
    }
    desc[0] = desc[1];
    desc_max[0] = desc_max[1];

    ll ans = 0LL;
    repp(i, N+2){
        ll tmp = asc[i];
        ll d = (i < N+1?desc_max[i+1]:0);
        if(d > sushi[i].first) tmp += - sushi[i].first + d;
        ans = max(ans, tmp);

        tmp = desc[i];
        d = (i!=0?asc_max[i-1]:0);
        if(d > C-sushi[i].first) tmp += - (C-sushi[i].first) + d;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}