#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;
    map<int, int> d;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (d.count(tmp))
            d[tmp]++;
        else
            d[tmp] = 1;
    }
    int m;
    cin >> m;
    vector<int> T(m);
    map<int, int> t;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        T[i] = tmp;
        if (t.count(tmp))
            t[tmp]++;
        else
            t[tmp] = 1;
    }
    string ans = "YES";
    for (int i = 0; i < m; i++) {
        if (!d.count(T[i])) {
            ans = "NO";
        } else if (d.at(T[i]) < t.at(T[i])) {
            ans = "NO";
        }
    }
    cout << ans << endl;
    return 0;
}