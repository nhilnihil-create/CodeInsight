#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    ll a = 1, b  = 1;
    cin >> N;
    for(ll i = 0;i < N;i++) {
        ll temp;
        cin >> temp;
        a *= 3;
        if(temp % 2 == 0) b *= 2;
    }
    cout << a - b << endl;
    return 0;
}
