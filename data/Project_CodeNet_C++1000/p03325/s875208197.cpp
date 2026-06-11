#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;
const double eps = 1e-9;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        while (x % 2 == 0)
            x /= 2, ans++;
    }
    cout << ans << endl;
}