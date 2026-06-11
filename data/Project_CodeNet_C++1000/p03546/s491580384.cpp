#include <bits/stdc++.h>
using namespace std;
int main() {
    long long h, w, c[10][10], s = 0, m;
    cin >> h >> w;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) cin >> c[i][j];
    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++) 
        {
            cin >> m;
            if (m >= 0) s += c[m][1];
        }
    }
    cout << s;
}