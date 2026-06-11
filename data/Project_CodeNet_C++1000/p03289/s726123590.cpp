#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    int m_c(0), c_index(-1);
    cin >> S;
    if (S.at(0) == 'A')
    {
        for (int i = 2; i < S.size() - 1; ++i)
        {
            if (S[i] == 'C')
            {
                m_c++;
                c_index = i;
            }
        }
        if (m_c == 1)
        {
            bool ans(true);
            for (int i = 1; i < S.size(); ++i)
            {
                if (i == c_index)
                    continue;
                if (isupper(S[i]))
                    ans = false;
            }
            if (ans == true)
            {
                cout << "AC" << endl;
                return 0;
            }
        }
    }
    cout << "WA" << endl;
}