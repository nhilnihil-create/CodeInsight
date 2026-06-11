#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    for (int b = 1; b <= N; b++) {
        if (b <= K) continue;
        ans += N/b * (b-K);
        if(N%b != 0 && K!=0){
          ans += max((N % b) - (K - 1), 0);
        } else if(N%b != 0 && K ==0){
          ans += N%b;
        }
    }
    cout << ans << endl;
}