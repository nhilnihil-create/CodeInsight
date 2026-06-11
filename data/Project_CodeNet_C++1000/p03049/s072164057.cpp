#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s.at(i);
    }

    int xabx = 0, bxxa = 0, xxxa = 0, bxxx = 0;
    for (int i = 0; i < N; i++)
    {
        string si = s.at(i);
        for (int j = 0; j < si.size() - 1; j++)
        {
            if (si.at(j) == 'A' && si.at(j + 1) == 'B')
            {
                xabx++;
            }
        }
        if (si.at(si.size() - 1) == 'A' && si.at(0) == 'B')
        {
            bxxa++;
        }
        else if (si.at(si.size() - 1) == 'A')
        {
            xxxa++;
        }
        else if (si.at(0) == 'B')
        {
            bxxx++;
        }
    }
    int res;
    if (xxxa > 0 || bxxx > 0)
    {
        res = xabx + min(xxxa + bxxa, bxxx + bxxa);
    }
    else if (bxxa > 0)
    {
        res = xabx + bxxa - 1;
    }
    else
    {
        res = xabx;
    }
    cout << res << endl;
}