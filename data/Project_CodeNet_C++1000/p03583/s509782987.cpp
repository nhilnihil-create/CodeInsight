#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    for(long long int i = 1; i <= 3500; ++i) {
        for(long long int j = 1; j <= 3500; ++j) {
            if(4*i*j-n*i-n*j == 0) continue;
            if((n*i*j)%(4*i*j-n*i-n*j) == 0 && (n*i*j)/(4*i*j-n*i-n*j) >= 1) {
                cout << i << " " << j << " " << ((n*i*j)/(4*i*j-n*i-n*j)) << '\n';
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << '\n';

    return 0;
}
