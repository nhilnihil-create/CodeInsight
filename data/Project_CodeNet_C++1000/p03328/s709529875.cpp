#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    ll a, b;
    cin >> a >> b;

    int ans;
    for(int n = 1; n <= 999; n++){
        int ax, bx;
        ax = n*(1+n)/2 - a;
        bx = (n+1)*(1+(n+1))/2 - b;
        if(ax == bx){
            ans = ax;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
