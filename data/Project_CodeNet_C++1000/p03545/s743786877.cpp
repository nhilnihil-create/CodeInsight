#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    ll A, B, C, D, a;

    cin >> a;
    A = a / 1000;
    B = a / 100 % 10;
    C = a / 10 % 10;
    D = a % 10;

    for (int i = -1; i < 2; i += 2) {
        for (int j = -1; j < 2; j += 2) {
            for (int k = -1; k < 2; k += 2) {
                if( A + B * i + C * j + D * k == 7){
                    cout << A << ((i == 1) ? '+' : '-');
                    cout << B << ((j == 1) ? '+' : '-');
                    cout << C << ((k == 1) ? '+' : '-');
                    cout << D << "=7\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}