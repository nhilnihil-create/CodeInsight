#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    vector<P> D(N);
    rep(i, N){
        int a, b; cin >> a >> b;
        D[i].first = a;
        D[i].second = b;
    }
    sort(D.begin(), D.end());
    int now = 0;
    ll ans = 0;
    rep(i, N){
        ll b = D[i].second;
        if(now+b > M){
            b = M - now;
        }
        now += b;
        ans += b * D[i].first;
        if(now == M)break;
    }

    cout << ans << endl;

    return 0;
}