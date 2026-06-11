#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m, d; cin >> n >> m >> d;
    if(d==0){
        cout << setprecision(10) << (double) (m-1) / n << endl;
    } else {
        cout << setprecision(10) << 2.0 * (n-d) / n / n * (m-1) << endl;
    }
}