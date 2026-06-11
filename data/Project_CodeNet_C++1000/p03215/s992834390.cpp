typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,k;
    std::cin >> n>>k;
    vector<ll> a(n);

    vector<ll> sumb;
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        sumb.push_back(a[i]);
        for (int j = i+1; j < n; j++) {
            sumb.push_back(sumb.back()+a[j]);
        }
    }
    
    ll mask = 0;
    for (int j = 40; j >=0; j--) {
        ll tmp = 0;
        for (int i = 0; i < sumb.size(); i++) {
            if( (sumb[i] & (((ll)1<<j) | mask)) == (((ll)1<<j) | mask)) tmp++;
        }
        if(tmp>=k){
            mask |= ((ll)1<<j);
        } 
    }
    std::cout << mask << std::endl;
}
