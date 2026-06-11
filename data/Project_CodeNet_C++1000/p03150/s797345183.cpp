#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (int i = (m); i < (int)(n); i++)

int main()
{
    string S, T = "keyence", tmp;
    int N;

    cin >> S;
    if (S == T)
    {
        cout << "YES" << endl;
        exit(0);
    }

    N = S.length();

    REP(i, N)
    {
        FOR(j, i, N)
        {
            tmp = "";
            REP(k, N)
            {
                if (k < i || j < k)
                    tmp += S[k];
            }
            if (tmp == T)
            {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }
    cout << "NO" << endl;
}