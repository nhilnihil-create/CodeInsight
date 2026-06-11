#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

string sol;

void f(ll n)
{
}

int main()
{
    ll n;
    cin >> n;
    string sol(100, '0');
    while (n != 0)
    {
        if (n > 0)
        {
            ll i = 1, s = 1;
            while (s < n)
                i *= 4, s += i;
            n -= i;
            sol[__builtin_ctzll(i)] = '1';
        }
        else
        {
            ll i = 2, s = 2;
            while (s < -n)
                i *= 4, s += i;
            n += i;
            sol[__builtin_ctzll(i)] = '1';
        }
    }
    while (sol.size() > 1 && sol.back() == '0')
        sol.pop_back();
    reverse(all(sol));
    cout << sol;
}
