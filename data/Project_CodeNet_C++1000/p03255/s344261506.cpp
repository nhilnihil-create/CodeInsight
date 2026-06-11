#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, X;
int x[220000];
signed main() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++)cin >> x[i];
    for (int i = 2; i <= N; i++)x[i] += x[i - 1];
    unsigned int ans = LLONG_MAX;
    for (int i = 1; i <= N; i++) {
        unsigned int cur = X * i + (x[N] - x[N - i]) * 5;
        int co = 5, st = N - i;
        while (st > 0) {
            if (st - i >= 0)cur += (x[st] - x[st - i]) * co;
            else cur += x[st] * co;
            st -= i;
            co += 2;
        }
        ans = min(ans, cur);
    }
    cout << ans + N*X << endl;
}
