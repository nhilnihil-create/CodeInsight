#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;
    if(a%b == 0) {
        cout << -1 << '\n';
        return 0;
    }
    for(long long int i = 1; i < 1000000000; ++i) {
        if(a*i%b != 0) {
            cout << a*i << '\n';
            return 0;
        }
    }

    return 0;
}
