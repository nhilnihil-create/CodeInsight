#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    double n, m, d, k = 2.0; cin >> n >> m >> d;
    if(!d) k = 1.0;
    cout << fixed << setprecision(12) << (m-1) * ((k * (n - d)) / (n * n));    
}