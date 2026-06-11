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

        while (h[i] == 0)
        {
            i++;
        }

        bool done = false;
        while (i < N && h[i] > 0)
        {
            h[i]--;
            i++;
            done = true;
        }

        bool allzero = true;
        for (int i = 0; i < N; i++)
        {
            if (h[i] > 0)
                allzero = false;
        }
        if (done)
            cnt++;

        if (allzero)
            break;
    }

    cout << cnt << endl;

    return 0;
}
