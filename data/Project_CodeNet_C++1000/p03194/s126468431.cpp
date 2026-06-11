#include <iostream>
using namespace std;
typedef long long Int;
 
int main() {
    Int n, p;
    cin >> n >> p;
    if (n == 1) {
        cout << p << '\n';
        return 0;
    }
    Int c = 0;
    Int res = 1;
    for (Int i = 2; i*i <= p; i++) {
        c = 0;
        while (p%i == 0) {
            p /= i;
            c++;
            if (c%n == 0) res *= i;
        }
    }
    cout << res << '\n';
    return 0;  
}