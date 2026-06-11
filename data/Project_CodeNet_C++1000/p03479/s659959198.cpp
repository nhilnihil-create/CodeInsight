#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y;
    cin >> x >> y;
    int count=0;
    while(x<=y) {
        x*=2;
        count++;
    }
    cout << count << "\n";

    return 0;
}