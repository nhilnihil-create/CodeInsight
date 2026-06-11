#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

const long long INF = 1LL << 60;

int main()
{
    int k;
    cin >> k;
    int ans = k % 2 == 0 ? k * k / 4 : ((k + 1) / 2) * (k / 2);
    cout << ans << endl;

    return 0;
}
