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

ll a , b;

ll f(ll x)
{
    ll zero = (x & 1);
    ll last = ((x >> 1) & 1);

    if(last == 0 && zero == 1)
        return 1;
    else if(last == 1 && zero == 1)
        return 0;
    else if(last == 1 && zero == 0)
        return x + 1;
    else return x;
}

int main()
{
    ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);

    cin >> a >> b;
    cout << (f(b) ^ f(a - 1));

    return 0;
}
