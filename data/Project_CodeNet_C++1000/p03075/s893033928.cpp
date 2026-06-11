#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int a[5];
    repi(i, 5, 0)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    bool ans = true;
    repi(i, 5, 0)
    {
        repi(j, 5, 0)
        {
            if (abs(a[i] - a[j]) > k)
                ans = false;
        }
    }
    cout << (ans ? "Yay!" : ":(") << endl;
    return 0;
}