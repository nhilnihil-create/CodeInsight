#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> mat(n);
    for (int i = 0; i < n; i++)
    {
        mat[i] = vector<char>(n);
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool valid = true;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int rr = r;
                int cc = (c - i + n) % n;
                if (mat[r][c] != mat[cc][(rr + i) % n])
                    valid = false;
            }
        }
        if (valid)
            ans += n;
    }
    cout << ans << endl;
    return 0;
}
