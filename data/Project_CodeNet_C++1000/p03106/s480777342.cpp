#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll A, B, K; cin >> A >> B >> K;
    ll i = min(A, B) + 1;
    while (K > 0) {
        i--;
        if (A % i == 0 && B % i == 0) {
            K--;
        }
    }
    cout << i << endl;
}