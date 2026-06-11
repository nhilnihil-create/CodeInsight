#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll R, G, B, N;
    ll count = 0;
    cin >> R >> G >> B >> N;
    for(ll r = 0;r <= N / R;r++) {
        for(ll g = 0;g <= N / G;g++) {
            ll b = max(0LL, (N - r * R - g * G) / B);
            if(r * R + g * G + b * B == N) count++;
        }
    }
    cout << count << endl;
    return 0;
}
