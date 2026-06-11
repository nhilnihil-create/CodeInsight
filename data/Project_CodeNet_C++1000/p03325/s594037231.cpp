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
    int A[N];
    rep(i, N) cin >> A[i];
    ll ans = 0;
    rep(i, N) {
        while (true) {
            if (A[i] % 2 == 0) {
                A[i] /= 2;
                ans++;
            }
            else break;
        }
    }
    cout << ans << endl;



    return 0;
}
