#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}


int main() {
    string s; cin >> s; int ans = 0;
    for(int i = 1;i < s.length();i++){
        if(s[i] != s[i-1]) continue;
        if(s[i] == '1'){
            s[i] = '0';
        }else{
            s[i] = '1';
        }
        ans++;
    }
    cout << ans;
}
