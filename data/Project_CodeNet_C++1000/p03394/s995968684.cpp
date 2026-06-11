#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 30001;
int used[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    int cur = 1;
    ll s = 0;
    for (int i = 1; i < n; ++i) {
        while (cur % 2 && cur % 3) {
            ++cur;
        }
        a.push_back(cur);
        used[cur] = 1;
        s += cur;
        ++cur;
    }
    for (int i = 4; i < N; ++i) {
        if (used[i] || gcd(s, i) == 1 || (s + i) % 2 || (s + i) % 3) {
            continue;
        }
        cur = i;
        break;
    }
    for (int i : a) {
        cout << i << ' ';
    }
    cout << cur;
    return 0;
}