#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

//const long long MOD = 998244353;
//const long long MOD = 1000000007;

int main(){
    std::string S;
    std::cin >> S;
    ll N=(ll)S.size();

    ll ans=0, b=0;
    for(ll i=0; i<N; ++i){
        if(S[i]=='B'){
            ++b;
        }else{
            ans+=b;
        }
    }
    std::cout << ans;
    return 0;
}
