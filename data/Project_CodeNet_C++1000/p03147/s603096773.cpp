#include <bits/stdc++.h>
using namespace std;

int N;
int h[110];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    int cnt = 0;

    while (true)
    {
        int i = 0;

        while (i < N && h[i] == 0)
        {
            if (i == N - 1 && h[i] == 0)
            {
                cout << cnt << endl;
                return 0;
            }
            i++;
        }

        while (i < N && h[i] > 0)
        {
            h[i]--;
            i++;
        }
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
