#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double  
#define mp make_pair
inline void io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
}
int main()
{
    io();
    int a, b;
    cin >> a >> b;
    cout << max(a + a - 1, max(b + b - 1, a + b));
    return 0;
}