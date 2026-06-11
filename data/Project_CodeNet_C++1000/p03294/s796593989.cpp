#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n; cin >> n;

    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        long long t;
        cin >> t;
        ans += t - 1;
    }    
    cout << ans;
}