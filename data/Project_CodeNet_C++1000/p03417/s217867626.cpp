#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    ll N, M;
    cin >> N >> M;

    ll ans;
    if (N == 1 && M == 1)
    {
        ans = 1;
    }
    else if (N >= 2 && M >= 2)
    {
        ans = (N - 2) * (M - 2);
    }
    else if (N >= 2)
    {
        ans = N - 2;
    }
    else if (M >= 2)
    {
        ans = M - 2;
    }
    cout << ans << endl;
}