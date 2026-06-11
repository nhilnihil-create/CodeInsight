#include <iostream>
#include <vector>

using namespace std;
#define ll long long

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return n != 1;
}

int main() {
    int Q;
    cin >> Q;
    int l, r;
    vector<bool> pf(1e5 + 1, false);
    for(int i = 1; i <= 1e5; i++) {
        if(is_prime(i) && is_prime((i + 1) / 2)) {
            pf[i] = true;
        }
    }
    vector<int> csum(1e5 + 1, 0);
    for(int i = 0; i <= 1e5; i++) {
        if(pf[i]) {
            csum[i + 1] = csum[i] + 1;
        } else {
            csum[i + 1] = csum[i];
        }
    }
    for(int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << csum[r + 1] - csum[l] << endl;
    }
    return 0;
}