#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    d = max({a, b, c});
    e = min({a, b, c});
    f = a+b+c-(d+e);
    d*=10, d+=f+e;
    cout << d;

}
