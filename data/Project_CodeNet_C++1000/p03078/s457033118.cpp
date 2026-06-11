#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lb long double
#define pb push_back
#define l first
#define r second
#define qwerty3 -> first
#define qwerty4 -> second
#define umap unordered_map
#define uset unordered_set
#define pii pair < int , int >

using namespace std;

const int N = 5000005;
const int M = 1000000007;
const lb PI = acos(-1);

ll x , y , z , k;
ll a[N] , b[N] , c[N] , d[N] , s[N];

int main()
{
    ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);

    ll i , j;

    cin >> x >> y >> z >> k;

    for(i = 1 ; i <= x ; i++)
        cin >> a[i];

    for(i = 1 ; i <= y ; i++)
        cin >> b[i];

    for(i = 1 ; i <= z ; i++)
        cin >> c[i];

    ll m = 0 , cnt = 0;

    for(i = 1 ; i <= x ; i++)
        for(j = 1 ; j <= y ; j++)
            d[++m] = a[i] + b[j];

    sort(d + 1 , d + m + 1 , greater < ll > ());
    sort(c + 1 , c + z + 1 , greater < ll > ());

    m = min(m , k);

    for(i = 1 ; i <= m ; i++)
        for(j = 1 ; j <= z ; j++)
            s[++cnt] = d[i] + c[j];

    sort(s + 1 , s + cnt + 1 , greater < ll > ());

    for(i = 1 ; i <= k ; i++)
        cout << s[i] << '\n';

    return 0;
}
