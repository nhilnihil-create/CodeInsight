#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N, 0);
    rep(i, N) cin >> a.at(i);
    sort(a.begin(), a.end());
    
    int score = 0;
    rep(i, N) score += pow(-1, i) * a.at(N - i - 1);
    cout << score << endl;

    return 0;
}