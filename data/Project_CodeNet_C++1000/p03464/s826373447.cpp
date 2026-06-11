#include <bits/stdc++.h>

using namespace std;

const int MAXK = 1E5;
int a[MAXK];

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    if (a[k - 1] != 2)
        cout << -1 << endl;
    else
    {
        bool poss = true;
        long long bigGroups = 1;
        long long smallGroups = 1;
        for (int i = k - 2; i >= 0; i--)
        {
            long long A = a[i + 1];
            long long B = a[i];
            long long temp1 = 0;
            for (long long jump = A * (bigGroups + 1) / B; jump > 0; jump /= 2)
            {
                while ((temp1 + jump) * B / A <= bigGroups)
                    temp1 += jump;
            }
            if (temp1 * B / A < smallGroups || temp1 * B / A > bigGroups)
                poss = false;
            long long temp2 = 0;
            for (long long jump = A * (bigGroups + 1) / B; jump > 0; jump /= 2)
            {
                while ((temp2 + jump) * B / A < smallGroups)
                    temp2 += jump;
            }
            bigGroups = temp1;
            smallGroups = temp2 + 1;
        }
        if (poss)
            cout << smallGroups * a[0] << " " << bigGroups * a[0] + (a[0] - 1) << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
