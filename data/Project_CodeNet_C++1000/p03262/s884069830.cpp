#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, X; cin >> N >> X;
    vector<int> d(N);
    rep(i, N){
        int x; cin >> x;
        d[i] = abs(x-X);
    }

    int ans = d[0];
    for (int i = 1; i < N; i++){
        ans = __gcd(ans, d[i]);
    }
    
    cout << ans << endl;

    return 0;
}