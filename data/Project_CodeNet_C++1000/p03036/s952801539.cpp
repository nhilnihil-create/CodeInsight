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
    int r,d,x; cin >> r >> d >> x;
    for(int i = 0;i < 10;i++){
        cout << r * x - d << endl;
        x = r * x-d;
    }
}
