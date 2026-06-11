#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int N = s.size();
    int ans = 1e9;
    for (int i = 0; i < N - 2; i++) {
        string ss = s.substr(i, 3);
        int num = abs(753 - stoi(ss));
        ans = min(ans, num);
    }

    cout << ans << endl;
}