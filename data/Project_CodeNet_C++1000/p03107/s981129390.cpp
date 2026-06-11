#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    string S;
    cin >> S;

    int zero = 0;
    int one = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '0')
        {
            zero++;
        }
        else
        {
            one++;
        }
    }
    int ans = min(one, zero) * 2;
    cout << ans << endl;
}