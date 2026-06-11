#include <bits/stdc++.h>

using namespace std;
const int MAX = 305;

double p[MAX][MAX][MAX], ev[MAX][MAX][MAX];
int cnt[4];

int main()
{
    int n;

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        int a;

        cin >> a;

        ++cnt[a];
    }

    p[cnt[1]][cnt[2]][cnt[3]] = 1;

    for(int c = n; c >= 0; --c)
        for(int b = n; b >= 0; --b)
            for(int a = n; a >= 0; --a)
            {
                if(a + b + c == 0)
                    continue;

                if(a + b + c > n)
                    continue;

                double pWaste = (double)(n - (a + b + c)) / n;
                double evWaste = pWaste / (1 - pWaste) + 1;

                ev[a][b][c] += evWaste * p[a][b][c];

                if(a != 0)
                {
                    double currP = (double)a / (a + b + c);
                    p[a - 1][b][c] += p[a][b][c] * currP;
                    ev[a - 1][b][c] += ev[a][b][c] * currP;
                }
                if(b != 0)
                {
                    double currP = (double)b / (a + b + c);
                    p[a + 1][b - 1][c] += p[a][b][c] * currP;
                    ev[a + 1][b - 1][c] += ev[a][b][c] * currP;

                }
                if(c != 0)
                {
                    double currP = (double)c / (a + b + c);
                    p[a][b + 1][c - 1] += p[a][b][c] * currP;
                    ev[a][b + 1][c - 1] += ev[a][b][c] * currP;
                }
            }

    cout << setprecision(10);
    cout << ev[0][0][0];

    return 0;
}
