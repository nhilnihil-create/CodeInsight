#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> black(N), white(N);
    if (S[0] == '#') black[0]++;
    for (int i = 1; i < N; i++) {
        black[i] = black[i-1];
        if (S[i] == '#') black[i]++;
    }
    if (S[N-1] == '.') white[N-1]++;
    for (int i = N - 2; i >= 0; i--) {
        white[i] = white[i+1];
        if (S[i] == '.') white[i]++;
    }
    int ans = min(white[0], black[N-1]);
    for (int i = 0; i < N - 1; i++) ans = min(ans, black[i] + white[i+1]);
    cout << ans << endl;
}