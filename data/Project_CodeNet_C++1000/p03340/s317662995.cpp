#include <iostream>
#include <utility>
#include <queue>
#include <memory>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)

using namespace std;
using ll = long long;

ll func(ll n){
    return n*(n+1)/2;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int sum = 0;
    int xor_ = 0;
    ll ans = 0;
    ll l = 0,r = 0;
    ll former_r = 0;
    while(r < n){
        sum += a[r];
        xor_ ^= a[r];
        r++;


        if(sum != xor_){
            ans += func(r-l-1);
            
            if(former_r-l+1 > 0 && former_r > 0){
                ans -= func(former_r-l+1);
            }
            former_r = r-2;
            while(sum != xor_){
                sum -= a[l];
                xor_ ^= a[l];
                l++;
            }
        }
    }

    ans += func(r-l);
    if(former_r-l+1 > 0 && former_r > 0){
        ans -= func(former_r-l+1);
    }
    cout << ans << endl;
    return 0;
}
