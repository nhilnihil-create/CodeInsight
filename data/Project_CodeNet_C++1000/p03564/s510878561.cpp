#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, k;
    cin >> n >> k;
    int ans = 1;
    for(int i = 0; i < n; i++){
        if(ans*2 < ans+k) ans *= 2;
        else ans += k;
    }
    cout << ans << endl;
    
    return 0;
}