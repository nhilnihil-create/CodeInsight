#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 105;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1 - i - n % 2; i++) {
        a[i] = a[n - 1 - i - n % 2] = i;
    }

    if (n % 2)
        a[n - 1] = n;


    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) {
                v.push_back({i, j});
            }
        }
    }

    int s[105];
    memset(s, 0, sizeof(s));

    for (auto p : v) {
        s[p.first] += p.second + 1;
        s[p.second] += p.first + 1;
    }

    cout << v.size() << "\n";
    for (auto p : v) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
    return 0;
};