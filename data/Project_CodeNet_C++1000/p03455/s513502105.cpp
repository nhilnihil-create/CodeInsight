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
    string odd_even(int a, int b)
    {
        int multi = a * b;
        return (multi % 2 == 0) ? "Even" : "Odd";
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Solution s;
    cout << s.odd_even(a, b) << endl;
    return 0;
}
