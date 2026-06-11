#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    set<char> Arale;
    rep(i, n) {
        char ch;
        cin >> ch;
        Arale.insert(ch);
    }

    if (Arale.size() == 3)
        cout << "Three";
    else
        cout << "Four";
}
