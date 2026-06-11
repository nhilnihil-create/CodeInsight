#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string Sd, T;
    cin >> Sd;
    cin >> T;

    string S = "UNRESTORABLE";

    int start = 0;
    vector<string> match_results;

    bool containded = false;
    rep(i, Sd.size() - T.size() + 1)
    {
        containded = true;
        rep(j, T.size())
        {
            if (Sd.at(i + j) != T.at(j) && Sd.at(i + j) != '?')
            {
                containded = false;
            }
        }

        if (containded)
        {
            string match_result = (Sd.substr(0, i) + T + Sd.substr(i + T.size(), Sd.size()));
            replace(match_result.begin(), match_result.end(), '?', 'a');
            match_results.push_back(match_result);
        }
    }

    if (match_results.size() > 0)
    {
        sort(match_results.begin(), match_results.end());
        S = match_results.at(0);
    }

    cout << S << endl;
    return 0;
}