#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct cake {
    ll x, y, z;
};

ll calc(vector<cake>& C, int M, std::function<bool(const cake&, const cake&)> comp) {
    sort(C.begin(), C.end(), comp);
    ll X = 0, Y = 0, Z = 0;
    for (int i = 0; i < M; i++) {
        X += C[i].x;
        Y += C[i].y;
        Z += C[i].z;
    }
    return abs(X) + abs(Y) + abs(Z);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<cake> C(N);
    for (int i = 0; i < N; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        C[i] = cake({x, y, z});
    }

    ll ans = 0;
    for (int n = 0; n < (1 << 3); n++) {
        int c[3];
        int temp = n;
        for (int i = 0; i < 3; i++) {
            if (temp % 2 == 1) {
                c[i] = 1;
            } else {
                c[i] = -1;
            }
            temp /= 2;
        }
        ans = max(ans, calc(C, M, [&](const cake& a, const cake& b) { return c[0] * a.x + c[1] * a.y + c[2] * a.z > c[0] * b.x + c[1] * b.y + c[2] * b.z; }));
    }
    cout << ans << endl;
}
