#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

int main() {
    string s;
    cin >> s;
    bool judge = false;
    rep(i, 7) {
        string k, kk;
        k = s.substr(0, i);
        kk = s.substr(s.size() - 7 + i);
        if (k + kk == "keyence")
            judge = true;
    }

    if (judge)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}