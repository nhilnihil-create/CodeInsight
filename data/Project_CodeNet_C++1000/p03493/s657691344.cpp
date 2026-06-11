#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

class Solution
{
public:
    int count_num(string s)
    {
        int ans = 0;
        rep(i, 3)
        {
            if (s[i] == '1')
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.count_num(str) << endl;
    return 0;
}
