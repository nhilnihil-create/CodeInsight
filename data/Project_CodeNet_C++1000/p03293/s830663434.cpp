#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;
    for (int n = 0; n < S.size(); ++n)
    {
        char tmp = S[S.size() - 1];
        for (int i = S.size() - 1; i > 0; --i)
        {
            S[i] = S[i - 1];
        }
        S[0] = tmp;
        if (S == T)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}