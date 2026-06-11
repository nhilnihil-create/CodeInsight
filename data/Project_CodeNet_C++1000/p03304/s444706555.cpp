#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double n, m, d;

int main() {
    cout << fixed << setprecision(10);

    cin >> n >> m >> d;

    if (d == 0) cout << (m-1)/n << endl;
    else {
        cout << (m-1)*2*(n-d)/n/n << endl;
    }
    
    return 0;
}
