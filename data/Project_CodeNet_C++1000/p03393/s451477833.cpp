#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool alph[26];
int main()
{
    string S, ans = "";
    cin >> S;
    int N = S.size();
    char c = S[0];
    for (int i = 0; i < N; i++)
    {
        int c1 = int(S[i] - 'a');
        alph[c1] = true;
    }
    if (N < 26)
    {
        rep(i, 26)
        {
            if (alph[i] == true)
                continue;
            else
            {
                ans = S + char(i + 'a');
                cout << ans << endl;
                return 0;
            }
        }
    }
    else
    {
        if (S == "zyxwvutsrqponmlkjihgfedcba")
        {
            cout << -1 << endl;
        }
        else
        {
            int i;
            for (i = 25; i > 0; i--)
            {
                alph[int(S[i] - 'a')] = false;
                if (S[i] > S[i - 1])
                    break;
            }
            //            cout << -1 << endl;
            rep(j, i - 1) cout << S[j];
            rep(k, 26)
            {
                if (alph[k] == false && S[i - 1] < char(k + 'a'))
                {
                    cout << char(k + 'a') << endl;
                    return 0;
                }
            }
        }
    }
}