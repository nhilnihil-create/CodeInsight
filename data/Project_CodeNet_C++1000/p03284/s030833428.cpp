#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    cout << (n + k - 1) / k - n / k << endl;
}
