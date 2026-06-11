#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

bool one, nine, seven, four;

int main() {
    rep(i,4){
        int n;
        cin >> n;
        if (n == 1) one = true;
        if (n == 9) nine = true;
        if (n == 7) seven = true;
        if (n == 4) four = true;
    }
    puts((one && nine && seven && four ? "YES" : "NO"));
}