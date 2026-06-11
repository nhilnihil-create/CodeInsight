#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N, M;
    cin >> N >> M;

    ll ans = 0;
    // init
    ll ac = ((N - M) * 100) * (pow(2, M));
    ll tle = (pow(2, M) * 1900) * M;
    ans = ac + tle;
    cout << ans << endl;
    return (0);
}