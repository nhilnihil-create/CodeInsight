#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ldouble = long double;
 
const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s) cout << fixed << setprecision(10) << s << endl;

string res;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    set<ll> s;

    for (ll i = 0; i < k; i++)
    {
        if (a + i > b)
        {
            break;
        }
        s.insert(a + i);
    }

    for (ll i = k - 1; i >= 0; i--)
    {
        if (b - i < a)
        {
            break;
        }
        s.insert(b - i);;
    }
    
    for (ll i : s)
    {
        println(i);
    }
    
}