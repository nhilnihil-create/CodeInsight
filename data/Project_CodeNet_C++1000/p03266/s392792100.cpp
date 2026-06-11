#include <bits/stdc++.h>
using namespace std;

//long long型(64bit整数)
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k % 2 == 0){
        ll count1 = 0, count2 = 0;
        for(ll i=1; i<=n; i++){
            if(i % k == 0) count1++;
            if(i % k == k/2) count2++;
        }
        ans = (count1 * count1 * count1 + count2 * count2 * count2);
    }else{
        ll count3 = 0;
        for(ll i=1; i<=n; i++){
            if(i % k == 0) count3++;
        }
        ans = (count3 * count3 * count3);
    }
    
    cout << ans << endl;
    return 0;
}