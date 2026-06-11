#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, c, solveCnt = 0, result = 0;
    cin >> n >> m >> c;
    int amat[n][m] = {0}, bmat[m] = {0};
    for (int i = 0; i < m; i++)
        cin >> bmat[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> amat[i][j];
    for (int i = 0; i < n; i++){
        result = 0;
        for (int j = 0; j < m; j++){
            result += amat[i][j] * bmat[j];
        }
        if(result + c > 0)
            solveCnt++;
    }
    cout << solveCnt << "\n";
    return 0;
}
