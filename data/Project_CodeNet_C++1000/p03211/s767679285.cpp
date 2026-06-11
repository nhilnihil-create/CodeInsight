#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string S;
    cin >> S;
    int ans = MOD;
    for (int i = 0; i < S.size() - 2; i++)
    {
        string tmp = S.substr(i, 3);
        int tmp2 = atoi(tmp.c_str());
        ans = min(ans, abs(tmp2 - 753));
    }
    cout << ans;
}