#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    ll ans = 0;
    for (int b = K+1; b <= N; b++){
        int x = (N-1)/b + 1;
        ans += x * (b-K);
        int a;
        if(K != 0){
            a = min(b*x-1-N, b-K);
            a = max(a, 0);
        } else {
            a = min(b*x-N, b-K);
            a = max(a, 0);
        }
        ans -= a;
    }

    cout << ans << endl;

    return 0;
}