#include <bits/stdc++.h>
using namespace std;

int main(int, char**) {
        long n, m, d;
        cin >> n >> m >> d;
        long double ninv = 1.0/n;
        int par = 2;
        if (d==0) par = 1;
        long double p = par * (1 - d * ninv) * ninv * (m - 1.0);
        cout << setprecision(13) << p << endl;
        return 0;
}
