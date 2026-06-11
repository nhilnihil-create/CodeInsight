#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll n, m, d;
    cin >> n >> m >> d;
    long double unit = 0;
    unit += (n - d) * 2;
    if(d == 0)unit = n;
    unit /= n * n;
    cout << fixed <<setprecision(12) << unit * (m - 1) << endl; 
}