#include <iostream>
#include <map>
using namespace std;
typedef long long int ll;

map<ll, ll> M;

ll N, P, ans = 1;

void disassemble(ll p)
{
    for (ll i = 2; i * i <= p; i++)
    {
        ll cnt = 0;
        while (p % i == 0)
        {
            cnt++;
            p /= i;
            if (cnt == N)
            {
                ans *= i;
                cnt = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> P;
    disassemble(P);
    if (N == 1)
    {
        cout << P << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}