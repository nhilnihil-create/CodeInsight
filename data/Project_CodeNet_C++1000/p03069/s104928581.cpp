#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int l[N], r[N];

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '.' + s;
    for (int i = 1; i <= n; i++) {
        l[i] = l[i - 1] + (s[i] == '#');
    } 
    for (int i = n; i >= 1; i--) {
        r[i] = r[i + 1] + (s[i] == '.');
    }
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, l[i] + r[i] - 1);
    }
    cout << mn << '\n';
}