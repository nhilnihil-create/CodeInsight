#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; cin >> n;

    int sx = 0,sy = 0,diff = 0;
    
    string ans = "Yes";
    for(int i = 0;i < n;i++){
        int a,b,c; cin >> a >> b >> c;
        sx = abs(sx-b); sy = abs(sy-c);
        diff = abs(a-diff);
        if(sx+sy > diff || diff % (sx+sy) != 0){
            ans = "No";
            break;
        }
        sx = b; sy = c; diff = a;
    }
    cout << ans;
}

