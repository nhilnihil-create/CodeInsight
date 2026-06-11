//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int n, m, c, flag = 0, total = 0, i, j;
    cin >> n >> m >> c;

    vector<int> b(n);
    vector<vector<int>> a(n, vector<int> (m));

    for(i = 0; i < m; i++) {
        cin >> b[i];
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            total += (b[j] * a[i][j]);
        }
        total += c;
        if(total > 0) flag++;
        total = 0;
    }

    cout << flag << '\n';

    return 0;
}
