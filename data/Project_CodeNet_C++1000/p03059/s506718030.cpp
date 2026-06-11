#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int a,b,t;
    cin >> a >> b >> t;
    int k=t/a;
    cout << k*b << endl;

    return 0;
}