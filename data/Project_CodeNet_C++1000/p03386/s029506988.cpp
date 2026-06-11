#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll a = 0, b = 0, k = 0;
    cin >> a >> b >> k;
    for(ll i = a;i <= b;i++) {
        if(i - a < k || b - i < k) cout << i << endl;
    }
   
   return 0;
}