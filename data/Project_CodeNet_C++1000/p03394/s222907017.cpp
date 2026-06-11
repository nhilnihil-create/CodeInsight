#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n;
vector<ll> V, W;
int main(void){
    // Your code here!
    cin >> n;
    if (n == 3){
        cout << 2 << ' ' << 5 << ' ' << 63 << endl;
        return 0;
    } if (n == 4){
        cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl;
        return 0;
    }
    V.push_back(0), W.push_back(0);
    for (ll i = 1; i <= 15000; i++){
        if (i % 3 == 0) continue;
        V.push_back(2 * i);
    }
    for (ll i = 1; i <= 10000; i++){
        W.push_back(i * 3);
    }
    ll k = n / 4, l = k / 2;
    if (n % 4 == 0){
        for (ll i = 1; i <= 4 * l; i++) cout << V[i] << ' ';
        for (ll i = 1; i <= 4 * (k - l); i++){
            cout << W[i];
            if (i < 4 * (k - l)) cout << ' ';
            else cout << endl;
        }
    } else if (n % 4 == 1){
        for (ll i = 1; i <= 4 * l + 2; i++) cout << V[i] << ' ';
        for (ll i = 1; i <= 4 * (k - l - 1) + 3; i++){
            cout << W[i];
            if (i < 4 * (k - l - 1) + 3) cout << ' ';
            else cout << endl;
        }
    } else if (n % 4 == 2){
        for (ll i = 1; i <= 4 * l + 2; i++) cout << V[i] << ' ';
        for (ll i = 1; i <= 4 * (k - l); i++){
            cout << W[i];
            if (i < 4 * (k - l)) cout << ' ';
            else cout << endl;
        }
    } else {
        for (ll i = 1; i <= 4 * (l + 1); i++) cout << V[i] << ' ';
        for (ll i = 1; i <= 4 * (k - l - 1) + 3; i++){
            cout << W[i];
            if (i < 4 * (k - l) + 3) cout << ' ';
            else cout << endl;
        }
    }
}
