#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    vector<tuple<int, int, int>> d(M);
    for (int i = 0; i < M; i++)
    {
        int p, y; cin >> p >> y;
        d[i] = make_tuple(p, y, i);
    }
    vector<vector<int>> out(M, vector<int>(12));
    sort(d.begin(), d.end());
    int np = 0;
    int num = 1, c1, c2;
    for (int i = 0; i < M; i++)
    {
        int p, y, x;
        tie(p, y, x) = d[i];
        if(np != p) {
            np = p;
            num = 1;
        }
        c1 = p; c2 = num;
        for (int j = 0; j < 6; j++)
        {
            out[x][j] = c2 % 10;
            c2 /= 10;
        }
        for (int j = 0; j < 6; j++)
        {
            out[x][j+6] = c1 % 10;
            c1 /= 10;
        }
        num++;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 11; j >= 0; j--)
        {
            cout << out[i][j];
        }
        cout << endl;
    }

    return 0;
}