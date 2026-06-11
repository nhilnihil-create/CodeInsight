#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    pair<int, int> q[m];//first:bi second:ai
    for(int i = 0; i < m; i++) {
        cin >> q[i].second >> q[i].first;
    }
    sort(q, q + m);
    int res = 0, l = 1;
    for (int i = 0; i < m; i++)
    {
        if(l <= q[i].second) {
            res++;
            l = q[i].first;
        }
    }

    cout << res << endl;
    return 0;
}