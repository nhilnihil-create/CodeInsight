#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<int> num1(N + 1, 0), num2(N + 1, 0);
    rep(1, i, N + 1)
    {
        if (S.at(i - 1) == 'W')
        {
            num1.at(i) = num1.at(i - 1) + 1;
        }
        else
        {
            num1.at(i) = num1.at(i - 1);
        }
    }

    reverse(all(S));
    rep(1, i, N + 1)
    {
        if (S.at(i - 1) == 'E')
        {
            num2.at(i) = num2.at(i - 1) + 1;
        }
        else
        {
            num2.at(i) = num2.at(i - 1);
        }
    }
    reverse(all(num2));

    int num, ans = N;
    rep(0, i, N + 1)
    {
        if (i != N)
        {
            num = num1.at(i) + num2.at(i + 1);
            ans = min(ans, num);
        }
        else
        {
            ans = min(ans, num1.at(N));
        }
    }

    cout << ans << endl;
}