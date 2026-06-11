/**
 *    author:  FromDihPout
 *    created: 2020-08-12
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> c(n-1), s(n-1), f(n-1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = i; j < n - 1; j++) {
            t = max(t, s[j]);
            int next = (t / f[j]) + (t % f[j] != 0);
            t = next * f[j];
            t += c[j];
        }
        
        cout << t << '\n';
    }
    return 0;
}