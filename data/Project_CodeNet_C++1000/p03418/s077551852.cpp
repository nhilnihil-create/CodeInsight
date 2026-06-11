#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define D1(a) cout<<#a<<":"<<a<<"\n"

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll N, K; cin >>N>>K;

    ll ans = 0;

    for (ll b = K+1; b <= N; b++) {
        ans += (b-K) * (N/b);
        ll r = N % b;
        if (r != 0 && r >= K) {
            ans += r - max((ll)0, K-1);
        }
    }

    cout << ans << endl;
}
