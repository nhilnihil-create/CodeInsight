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


int main()
{
    string s;
    cin >> s;

    vector<ll> a(3);
    for (ll i = 0; i < 3; i++)
    {
        a[s[i] - 'a']++;
    }

    string res = "Yes";
    for (ll i = 0; i < 3; i++)
    {
        if (a[i] != 1)
        {
            res = "No";
        }
    }

    println(res);
}
