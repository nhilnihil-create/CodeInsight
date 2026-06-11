#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, K;

vector<int> w;


void input() {
    cin >> N >> K;
}


int main() {
    input();
    w = vector<int>(K, 0);
    rep(i, N) w[(i + 1) % K]++;
    ll ans = pow(w[0], 3);
    if (K % 2 == 0) {
        ans += pow(w[K / 2], 3);
    }
    cout << ans << endl;
}
