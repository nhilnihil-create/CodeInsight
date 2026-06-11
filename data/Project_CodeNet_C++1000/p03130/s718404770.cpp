#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    map<int, int> mp;
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }
    bool flag = true;
    for (auto x: mp) {
        if (x.second > 2) flag = false;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}