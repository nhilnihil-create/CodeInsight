#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b, t;
    cin >> a >> b >> t;
    int ans = 0;
    for(int i = a; i <= t; i+=a){
        ans += b;
    }
    cout << ans << endl;

    return 0;
}