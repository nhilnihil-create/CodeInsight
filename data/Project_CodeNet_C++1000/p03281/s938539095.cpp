#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

ll yakusuu(ll x){
    ll sum = 0;
    for(int i = 1;i <= x;i++){
        if(x%i == 0){
            sum++;
        }
    }
    //約数の個数
    return sum;
}

int main(){
    ll n;cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        if(yakusuu(i) == 8 && i%2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
}