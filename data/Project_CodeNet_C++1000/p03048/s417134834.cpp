#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int R, G, B, N; cin >> R >> G >> B >> N;
    const int N_MAX = 3000;

    ll cnt = 0;
    for (int i = 0; i <= N_MAX; i++) {
        for (int j = 0; j <= N_MAX; j++) {
            int x = N - i * R - j * G;
            int k = x / B;

            if (k < 0 || k > N_MAX) continue;
            if ((i * R + j * G + k * B) == N) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
