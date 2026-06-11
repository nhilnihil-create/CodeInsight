typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll k;
    std::cin >> k;
    vector<ll> a(k);
    
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }
    
    if(a[k-1]!=2){
        std::cout << -1 << std::endl;
        return 0;
    }
    
    ll minv = a[k-1];

    for (int i = k-2; i >= 0; i--) {
        ll l = 0;
        ll r = 1e18/a[i];
        
        while( r-l>1 ){
            ll m = (r+l)/2;
            // std::cout << m << std::endl;
            if( m*a[i] >= minv ){
                r = m;
            }else{
                l = m;
            }
        }
        
        minv = r*a[i];
    }
    ll maxv = 4;
    for (int i = k-2; i >=0; i--) {
        if(a[i]<maxv){
            ll l = 0;
            ll r = 1e18/a[i];
            
            while( r-l>1 ){
                ll m = (r+l)/2;
                if( m*a[i] >= maxv ){
                    r = m;
                }else{
                    l = m;
                }
            }
            maxv = r*a[i];
        }else{
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    
    if(minv>maxv-1){
        std::cout << -1 << std::endl;
        return 0;
    }
    
    std::cout << minv<<" "<<maxv-1 << std::endl;
}
