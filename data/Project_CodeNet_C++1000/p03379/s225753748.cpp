#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    multiset<ll> xs;
    ll x[n];
    rep(i, n)
    {
        cin >> x[i];
        xs.insert(x[i]);
    }
    auto itr_b = xs.begin();
    rep(i, n / 2 - 1) itr_b++;
    auto itr_1 = itr_b;
    itr_b++;
    auto itr_2 = itr_b;
    rep(i, n)
    {
        auto itr = xs.find(x[i]);
        if (*itr > *itr_1)
        {
            cout << *itr_1 << endl;
        }
        else
        {

            cout << *itr_2 << endl;
        }
    }
    return 0;
}