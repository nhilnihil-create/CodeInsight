#include <bits/stdc++.h>
using namespace std;
using Double = long double;
#define PUTS(x) cout << (x) << endl;
int main() {
    std::cout << std::fixed << std::setprecision(20);
    Double n, m, d;
    cin >> n >> m >> d;
    if(d==0){
        PUTS((m-1)/n);
    } else {
        PUTS(2 * (m - 1) * (n - d) / (n * n));
    }
}
