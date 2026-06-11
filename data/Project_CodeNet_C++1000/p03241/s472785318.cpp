#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    
    long long ans = -1;
    for (long long i = 1; i * i <= m; i++){
        if (m % i != 0) continue;
        long long temp = m / i;
        if (n * i <= m) ans = max(ans, i);
        if (n * temp <= m) ans = max(ans,temp);
    }
    cout << ans << endl;
}