#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;

    int ans = 0;
    while (!(A == B && B == C) || ans % 2 != 0)
    {
        ans += 1;
        if (A <= B && A <= C)
        {
            A++;
        }
        else if (B <= A && B <= C)
        {
            B++;
        }
        else
        {
            C++;
        }
    }
    ans /= 2;
    cout << ans << endl;
    return (0);
}