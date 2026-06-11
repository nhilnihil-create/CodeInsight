#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int aux[N];

int main() {
    int n, k;
    cin >> n >> k;
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int sz = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        aux[sz++] = it->second;
    }
    sort(aux, aux + sz);
    int res = 0;
    for (int i = 0; i < sz - k; i++) {
        res += aux[i];
    }
    cout << res;
    return 0;
}