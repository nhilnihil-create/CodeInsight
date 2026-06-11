#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> pow2(61);
void pre() {
    pow2[0] = 1;
    for (int i = 1; i < pow2.size(); i++) {
        pow2[i] = pow2[i-1]*2;
    }
}

int main() {
    pre();
    ll x, y; cin >> x >> y;
    ll MAX = 0;
    for (int i = 0; i < pow2.size(); i++) {
        if (y >= pow2[i]*x) MAX = i+1;
        else break;
    }
    cout << MAX << endl;
}