#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int r;
    cin >> r;
    if (r < 1200)
        cout << "ABC" << endl;
    else if (r < 2800)
        cout << "ARC" << endl;
    else
        cout << "AGC" << endl;
}
