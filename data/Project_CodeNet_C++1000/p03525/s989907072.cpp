typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> c(13);
    c[0]++;
    for (int i = 0; i < n; i++) {
        ll t;
        std::cin >> t;
        c[t]++;
        if(c[t]==3){
            std::cout << 0 << std::endl;
            return 0;
        }
        if( c[t]==2 && (t == 0 || t == 12) ){
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    vector<bool> have(24,false);
    
    vector<ll> ones;
    have[12] = true;
    if(c[12] == 1){
        have[0] = true;
    }
    for (int i = 1; i <= 11; i++) {
        if(c[i]==2){
            have[12+i] = true;
            have[12-i] = true;
        }else if(c[i] == 1){
            ones.push_back(i);
        }
    }
    ll minv = 0;
    
    for (int i = 0; i < ( 1<<ones.size() ); i++) {
        
        vector<bool> now_have(24,false);
        
        for (int j = 0; j < 24; j++) {
            now_have[j] = have[j];
        }
        
        for (int j = 0; j < ones.size(); j++) {
            if( i & (1<<j) ){
                now_have[12+ones[j]] = true;
            }else{
                now_have[12-ones[j]] = true;
            }
        }
        
        // for (int j = 0; j < 24; j++) {
        //     if(now_have[j]){
        //         std::cout << "1";
        //     }else{
        //         std::cout << "0";
        //     }
        // }
        ll kou = 25;
        
        // for (int j = 0; j < 24; j++) {
        //     if(now_have[j]){
        //         std::cout << "0";
        //     }else{
        //         std::cout << "1";
        //     }
        // }
        // std::cout << std::endl;

        for (int j = 0; j < 24; j++) {
            if(!now_have[j])continue;
            ll dif = 1;
            while(true){
                if( now_have[(j+dif)%24] ){
                    // std::cout << kou << std::endl;
                    kou = min(kou,min(dif,24-dif));
                    break;
                }else{
                    dif++;
                }
            }
        }
        minv = max(minv,kou);
    }
    
    std::cout << minv << std::endl;
}
