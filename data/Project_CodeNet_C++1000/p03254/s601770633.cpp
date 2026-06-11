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
    int n;ll x; cin >> n >> x;
    ll a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+sizeof(a)/sizeof(a[0]));
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(x >= a[i]){
          x -= min(a[i],x);
            cnt++;
        }else{
            cout << cnt;
            return 0;
        }
    }
    if(x > 0){
        cout << cnt-1;
    }else{
        cout << cnt;
    }
}

