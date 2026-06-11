#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    ll n;
    cin >> n;
    set<ll> a;
    ll tmp;
    rep(i, n)
    {
        cin >> tmp;
        a.insert(tmp);
    }
    set<ll> b;
    while (a.size() > 1)
    {
        b.clear();
        auto itr = a.begin();
        b.insert(*itr);
        ll a_min = *itr;
        rep(i, a.size() - 1)
        {
            itr++;
            if (*itr % a_min != 0)
                b.insert(*itr % a_min);
        }
        a = b;
    }
    auto res = a.begin();
    cout << *res << endl;
    return 0;
}