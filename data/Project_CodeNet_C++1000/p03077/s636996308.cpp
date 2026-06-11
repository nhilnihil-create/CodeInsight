#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const long long MAX = 1000000000000000 + 5;

int main()
{
    ll n;
    cin >> n;
    ll minv = MAX;
    for (int i = 0; i < 5; i++)
    {
        ll temp;
        cin >> temp;
        minv = min(minv, temp);
    }
    ll pack;
    if (n < minv)
    {
        pack = 1;
    }
    else
    {
        pack = (n % minv != 0) ? n / minv + 1 : n / minv;
    }
    
    ll ans = pack - 1 + 5;
    cout << ans << endl;
    return 0;
}