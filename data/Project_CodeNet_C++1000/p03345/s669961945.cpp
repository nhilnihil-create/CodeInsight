#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    if(K % 2) {
        cout << B - A << endl;
    } else {
        cout << A - B << endl;
    }
    return 0;
}
