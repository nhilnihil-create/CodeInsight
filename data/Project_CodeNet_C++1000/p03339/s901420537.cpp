#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    string S;
    cin >> N;
    cin >> S;

    int cnt = 0;
    for (int i = 1; i < N; i++)
    {
        if (S.at(i) == 'E')
        {
            cnt++;
        }
    }

    int min = cnt;
    for (int i = 0; i < N - 1; i++)
    {
        if (S.at(i) == 'W')
        {
            cnt++;
        }

        if (S.at(i + 1) == 'E')
        {
            cnt--;
        }

        if (min > cnt)
        {
            min = cnt;
        }
    }

    cout << min << endl;
    return 0;
}