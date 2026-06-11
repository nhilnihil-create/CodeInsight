#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    string bh;
    string hb;
    for (int i = 0; i < S.size(); i++)
    {
        if (i % 2 == 0)
        {
            bh += '0';
            hb += '1';
        }
        else
        {
            bh += '1';
            hb += '0';
        }
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == bh[i])
        {
            ++cnt1;
        }
        if (S[i] == hb[i])
        {
            ++cnt2;
        }
    }
    cout << min(cnt1, cnt2) << endl;
}