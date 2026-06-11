#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int K = S.size();
    for (int i = 1; i < S.size(); i++)
    {
        if (S[i - 1] != S[i])
        {
            K = min(K, max(i, (int)S.size() - i));
        }
    }
    cout << K << endl;
}
