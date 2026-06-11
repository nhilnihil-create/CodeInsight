#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


const int mod = 1e9 + 7;

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    string s;
    cin >> s;
    char t;

    vector<char> v, u;
    int ab[26] = {};
    rep(i, s.length())
    {
        v.push_back(s[i]);
        ab[s[i] - 'a']++;
    }
    u = v;
    if (v.size() == 26)
    {
        if (!next_permutation(v.begin(), v.end()))
            cout << -1 << endl;
        else
        {
            rep(i, 26)
            {
                cout << v[i];
                if (v[i] != u[i])
                    break;
            }
        }
    }

    else
    {
        rep(i, 26)
        {
            if (!ab[i])
            {
                t = i + 'a';
                break;
            }
        }
        cout << s << t << endl;
    }

    return 0;
}
