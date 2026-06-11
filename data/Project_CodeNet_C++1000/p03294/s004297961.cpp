#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    ll ans = 0;
    rep(i, N){
        int a; cin >> a;
        ans += a;
    }
    ans -= N;

    cout << ans << endl;

    return 0;
}