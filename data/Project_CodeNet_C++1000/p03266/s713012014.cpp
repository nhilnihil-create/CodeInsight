#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N, K;
    cin >> N >> K;
    ll ans = pow(N/K, 3);
    if (K % 2 == 0) {
        ans += pow((2*N/K+1)/2, 3);
    }
    cout << ans << endl;
}