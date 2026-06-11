#include <bits/stdc++.h>
using namespace std;

bool c[200][200];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        c[a][b] = true;
        //c[b][a] = true;
    }

    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        //v.push_back({b, a});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = -1, y = -1;

        for (int j = 0; j < v[i].second; j++) {
            for (int k = 0; k < v[i].first; k++) {
                if (c[k][j]) x = k, y = j;
            }
        }

        if (x != -1) {
            c[x][y] = false;
            ans++;
        }
    }

    cout << ans;
}
