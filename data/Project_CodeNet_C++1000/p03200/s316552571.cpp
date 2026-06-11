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
    string s; cin >> s;
    ll cnt = 0,ans = 0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == 'B'){
            cnt++;
        }else{
            ans += cnt;
        }
    }
    cout << ans;
}

