#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int res = INT_MAX;
    for (int i = 0; i + 2 < (int)S.size(); i++)
    {
        int x = stoi(S.substr(i, 3));
        res = min(res, abs(x - 753));
    }
    cout << res << endl;
    return 0;
}
