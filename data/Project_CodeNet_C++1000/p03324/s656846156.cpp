#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll D, N;
    cin >> D >> N;
    ll ans;
    if(N != 100){
        ans = pow(100,D) * N;
    }
    else{
        ans = pow(100,D) * 101;
    }
    cout << ans << endl;
}