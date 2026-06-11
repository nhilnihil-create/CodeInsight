#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, q, l, r; cin >> n >> m >> q;

    int part[505][505];
    memset(part, 0, sizeof part);

    for(int i=0; i<m; i++)
        cin >> l >> r, part[l][r]++;

    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            part[i][j] += part[i][j-1];

     for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            part[i][j] += part[i-1][j];

    while(q--){
        cin >> l >> r, l--;
        cout << (part[r][r]+part[l][l]) - (part[l][r]+part[r][l]) << '\n';
    }

    return 0;
}
