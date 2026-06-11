#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    /*ll k, a, b;
    cin >> k >> a >> b;
    if(b - a <= 2) {
        cout << 1 + k << endl;
        return 0;
    }
    ll count = 1; // クッキーの枚数。
    ll money = 0;
    rep(i, k) {
        if(money != 0) {
            count += b;
            money--;
            continue;
        }
        if(i == k - 1) {
            count++;
            continue;
        }
        if(count < a && money == 0 ) {
            count++;
            continue;
        }
        if(count >= a && i + 1 < k - 1) {
            money++;
            count -= a;
            continue;
        }
        
        
        
    }
    cout << count << endl;*/
    ll k, a, b;
    cin >> k >> a >> b;
    if(b - a <= 2 || a - 1 > k) {
        cout << 1 + k << endl;
        return 0;
    }
    k -= a - 1;
    ll count = a;
    ll n = floor(k / 2);
    rep(i, n) count += b - a;
    if(k % 2 == 1) count++;
    cout << count << endl;
    // cout << n << endl;
}