#include <bits/stdc++.h>
using namespace std;

int binary(int bina)
{
    int ans = 0;
    for (int i = 0; bina > 0; i++)
    {
        ans = ans + (bina % 2) * pow(10, i);
        bina = bina / 2;
    }
    return ans;
}

int main()
{
    int N;

    cin >> N;

    int F[N][10];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> F[i][j];
        }
    }
    int P[N][11];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cin >> P[i][j];
        }
    }

    int ans = 1;
    int score = INT_MIN;
    int max;
    string bit;
    int array[10];

    while (ans < 1024)
    {
        bit = to_string(binary(ans));
        bit = string(10 - bit.length(), '0') + bit;

        int i = 0;
        for (char c : bit)
        {
            array[i++] = c - '0';
        }

        int score_tmp = 0;
        for (int i = 0; i < N; i++)
        {
            int same = 0;
            for (int j = 0; j < 10; j++)
            {
                if (F[i][j] == 1 && array[j] == 1)
                {
                    same++;
                }
            }
            score_tmp += P[i][same];
        }

        if (score_tmp > score)
        {
            score = score_tmp;
        }

        ans++;
    }
    cout << score << endl;

    return 0;
}