#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    int k;
    cin >> s >> k;

    vector<string> sub;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= k && i + j - 1 <= s.length() - 1; j++)
        {
            string tmp = s.substr(i, j);
            sub.push_back(tmp);
        }
    }
    sort(sub.begin(), sub.end());
    unique(sub.begin(), sub.end());
    cout << sub[k - 1] << endl;
}