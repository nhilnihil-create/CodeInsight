#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    if (a + b - 1 > n) {
        cout << -1;
        return  0;
    }
    deque<int> q;
    for (int i = 1; i <= a; ++i) {
        q.push_back(i);
    }
    if (b > 1) {
        int z = (n - a) / (b - 1);
        if (z == 0) {
            cout << -1;
            return 0;
        }
        vector<int> kek(b - 1, z);
        for (int i = 0; i < (n - a) % (b - 1); ++i) {
            ++kek[i];
            if (kek[i] > a) {
                cout << -1;
                return 0;
            }
        }
        int cur = a + 1;
        for (int i : kek) {
            for (int j = cur + i - 1; j >= cur; --j) {
                q.push_front(j);
            }
            cur += i;
        }
    } else {
        if (a == n) {
            for (int i : q) {
                cout << i << ' ';
            }
        } else {
            cout << -1;
        }
        return 0;
    }
    for (int i : q) {
        cout << i << ' ';
    }
    return 0;
}