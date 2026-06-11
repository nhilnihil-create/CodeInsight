#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()

const int M = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    map<char, int> ma;
    for (auto e : s) ma[e]++;
    int ans = 1;
    for (auto e : ma) ans = ans * (e.y + 1) % M;
    ans--;
    if (ans < 0) ans += M;
    cout << ans;
    return 0;
}
