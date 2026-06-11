#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 105;

int n, a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) cnt++;
        else {
            ans += cnt / 2;
            cnt = 1;
        }
    }
    cout << ans + cnt / 2;
    return 0;
}