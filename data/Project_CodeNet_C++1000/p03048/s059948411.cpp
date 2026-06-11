#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    ll cnt = 0;
    for (int r = 0; r <= N; r++) {
        for (int g = 0; g <= N; g++) {
            if ((N - r * R - g * G) % B == 0) {
                int b = (N - r * R - g * G) / B;
                if (b >= 0 && b <= N)
                    cnt++;
            }
        }
    }

    cout << cnt << endl;
}