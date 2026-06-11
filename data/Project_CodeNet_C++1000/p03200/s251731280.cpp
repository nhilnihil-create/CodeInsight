#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    int64_t ans = 0, tmp = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'B')
        {
            ans += (i - tmp);
            tmp++;
        }
    }
    cout << ans;
}