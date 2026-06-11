#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main()
{
    int n, k;
    cin >> n >> k;
    ld res = 0;

    for(int i = 1; i <= n; i++) {
        int j, t = i;
        for(j = 0; t < k; t *= 2, j++);
        ld cur = 1.0/(1<<j);
        res += cur * ((ld)1/n);
    }
    cout << fixed <<setprecision(12) << res << endl; 
}