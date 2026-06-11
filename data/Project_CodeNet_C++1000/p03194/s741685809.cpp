#include <iostream>
using namespace std;

typedef long long ll;

ll power(int i, ll j)
{
    ll ret = 1;
    while (j > 0)
    {
        ret *= i;
        j--;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ll N, P;
    ll ans = 1;
    cin >> N >> P;
    if (N == 1)
    {
        cout << P << endl;
        return 0;
    }
    if (N >= 40)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; power(i, N) <= P; i++)
    {
        while (P % power(i, N) == 0)
        {
            ans *= i;
            P /= power(i, N);
        }
    }
    cout << ans << endl;

    return 0;
}
