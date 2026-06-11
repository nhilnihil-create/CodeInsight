#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll A, B, K;
    cin >> A >> B >> K;
    for(ll i = A;i <= B;i++) {
        if(i - A < K || B - i < K) cout << i << endl;
    }
    return 0;
}
