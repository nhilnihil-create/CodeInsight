#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    map<int, int> mp;
    int a;
    rep(i, N) {
        cin >> a;
        if (mp.count(a)) mp[a]++;
        else mp[a] = 1;
    }

    int ans = 0;
    for (auto itr=mp.begin(); itr != mp.end(); itr++) {
        if (itr->second >= itr->first) ans += itr->second - itr->first;
        else ans += itr->second;
    }

    cout << ans << endl;

    return 0;
}