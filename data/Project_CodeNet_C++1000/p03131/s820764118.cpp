#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll k, a, b; cin >> k >> a >> b;
    ll ans = 1;
    if(a >= b || (a<b && (b-a <= 2))){
        ans += k;
    }else{
        ll a_dis = a - 1;
        ans += a_dis; k-= a_dis; // 所持数をA枚まで持っていく
        if(k%2==0){
            ans += (b-a) *(k/2);
        }else{
            ans += (b-a) *(k/2) + 1;
        }
    }
    cout << ans << endl;
    return 0;
}