#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

bool solve(string s, string t) {
    sort(ALL(s));
    sort(ALL(t), greater<char>());
    if (s < t) return true;
    else return false;
}

int main() {
    string s, t;
    cin >> s >> t;
    if (solve(s, t)) cout << "Yes" << endl;
    else cout << "No" << endl;
}