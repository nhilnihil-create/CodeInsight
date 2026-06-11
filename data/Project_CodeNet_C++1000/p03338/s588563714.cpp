#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

ll solve(std::string l, std::string r){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::vector<std::vector<bool>> cnt(26,std::vector<bool>(2, false));
    for(int i=0; i<l.size(); ++i){
        for(int j=0; j<26; ++j){
            if(l[i]==alphabet[j]) cnt[j][0]=true;
        }
    }
    for(int i=0; i<r.size(); ++i){
        for(int j=0; j<26; ++j){
            if(r[i]==alphabet[j]) cnt[j][1]=true;
        }
    }
    ll ret=0;
    for(int i=0; i<26; ++i){
        if(cnt[i][0]&&cnt[i][1]) ++ret;
    }
    return ret;
}

int main(){
    ll n; std::cin >> n;
    std::string s; std::cin >> s;

    ll ans = 0;
    for(int i=1; i<n; ++i){
        std::string l = s.substr(0,i);
        std::string r = s.substr(i);
        ans = std::max(ans, solve(l, r));
    }
    std::cout << ans;
    return 0;
}
