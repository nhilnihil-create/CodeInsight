#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

const long long INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n << endl;
    }
    else
    {
        cout << n * 2 << endl;
    }
    return 0;
}
