#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e9

ll axes[200];

int main ()
{
    ll r, d, x; cin >> r >> d >> x;
    axes[0] = x;
    for (int i = 1; i <= 10; i++) {
        cout << (axes[i] = r * axes[i-1] - d) << endl;
    }
    return 0;
}
