#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N;
    cin >> N;
    int H[N];
    rep(i, N) cin >> H[i];
    int ans = 0;
    rep(i, N - 1) if (H[i] > H[i + 1]) ans += H[i] - H[i + 1];
    ans += H[N - 1];

    cout << ans << endl;





    return 0;
}
