#include <bits/stdc++.h>
using namespace std;

int main()
{
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
    string c[3];

    REP(i, 3)
    {
            cin >> c[i];
    }

    cout << c[0].at(0) << c[1].at(1) << c[2].at(2) << endl;
}