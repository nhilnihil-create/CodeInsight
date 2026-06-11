#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    long long m = (long long)1e16;
    for(int i = 0; i < 5; i++){
        long long a; cin >> a;
        m = min(m, a);
    }
    long long ans = 4;
    ans += (n + m - 1)/m;
    cout << ans << endl;
}