#include <bits/stdc++.h>

using namespace std;

int Count(string s)
{
    int best = 0, temp = 0;
    for (char c : s)
    {
        if (!(c == 'A' || c == 'T' || c == 'C' || c == 'G')) temp = 0;
        else temp++;
        best = max(best, temp);
    }
    return best;
}

int main()
{
    string s; cin >> s;
    int best = 0;
    for (int rmvst = 0; rmvst < (int)s.length(); rmvst++)
    {
        string substring = s.substr(rmvst);
        for (int rmvbk = 0; rmvbk < (int)substring.length(); rmvbk++)
        {
            string result = substring.substr(0, (int)substring.length() - rmvbk);
            best = max(best, Count(result));
        }
    }
    cout << best << "\n";
}