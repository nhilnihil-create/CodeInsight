#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    map<char, long long> march;
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        march[S[0]]++;
    }
    long long m, a, r, c, h;
    m = march['M'];
    a = march['A'];
    r = march['R'];
    c = march['C'];
    h = march['H'];
    long long ans;
    ans = m * a * (r + c + h) + (m * r + a * r) * (c + h) + (m + a + r) * c * h;
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}