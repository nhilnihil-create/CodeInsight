#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, Y;
    cin >> N >> Y;

    ll k = Y / 1000;
    if(k - N >= 0) {
        ll x, y, z;
        for(x = 0; x <= N; x++) {
            y = (k - N - 9*x) / 4;
            z = N - (x + y); 
            if((k - N - 9*x) % 4 == 0 && y >= 0 && z >= 0) {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl; 
    
    return 0;
}