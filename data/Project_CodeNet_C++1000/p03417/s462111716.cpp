#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    if(n>1) n-=2;
    if(m>1) m-=2;
    cout << n*m << "\n";

    return 0;
}