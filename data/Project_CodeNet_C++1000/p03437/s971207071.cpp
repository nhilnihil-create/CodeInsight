#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
    ll X;
    ll Y;
    cin >> X >> Y;
    cout << ((X % Y == 0) ? -1 : X) << endl;
}
