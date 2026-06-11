#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll n, a[5];
    cin >> n;
    for(ll i = 0; i < 5; i++)cin >> a[i];
    ll nin = *min_element(a, a + 5);
    cout << ((n + nin - 1) / nin) + 4 << endl;
}