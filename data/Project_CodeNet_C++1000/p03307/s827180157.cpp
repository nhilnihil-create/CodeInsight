#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pi 2*acos(0.0)
#define mod 998244353

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    if(n%2 == 0)
        cout << n<<endl;
    else
        cout << n*2<<endl;

    return 0;
}