#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
ll X[MAXN], Y[MAXN];
ll v[MAXN];

int xc[4] = {-1, 1, 0, 0};
int yc[4] = {0, 0, -1, 1};
string sc = "RLUD";

void gogo (ll xcur, ll ycur)
{
    for (int i = 0; i + 1 < M; i += 2)
    {
        ll cv = v[i];
        ll nv = cv * 3;
        for (int j = 0; j < 16; j++)
        {
            int cj = j;
            string act = "";
            for (int k = 0; k < 2; k++)
            {
                int cc = cj % 4;
                xcur += xc[cc] * cv;
                ycur += yc[cc] * cv;
                act += sc[cc];
                cj /= 4;
            }
            if (xcur % nv == 0 && ycur % nv == 0)
            {
                cout << act;
                break;
            }

            cj = j;
            for (int k = 0; k < 2; k++)
            {
                int cc = cj % 4;
                xcur -= xc[cc] * cv;
                ycur -= yc[cc] * cv;
                cj /= 4;
            }
            //if (j == 15)
            //    cout << "BAD\n";
        }
    }
    if (M % 2 == 1)
    {
        if (xcur < 0) cout << "L";
        else if (xcur > 0) cout << "R";
        else if (ycur < 0) cout << "D";
        else cout << "U";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    int m2 = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
        m2 = (X[i] + Y[i]) % 2;
    }
    m2 = abs (m2);

    for (int i = 0; i < N; i++)
        if ((X[i] + Y[i] + m2) % 2 != 0)
        {
            cout << "-1\n";
            return 0;
        }

    v[0] = v[1] = 1;
    for (int i = 2; i < 40; i++)
        v[i] = v[i-2] * 3;

    M = 40 - m2;
    cout << M << "\n";
    for (int i = 0; i < M; i++)
    {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";

    for (int i = 0; i < N; i++)
        gogo (X[i], Y[i]);
}