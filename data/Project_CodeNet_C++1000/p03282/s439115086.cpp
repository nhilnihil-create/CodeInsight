#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    for(int i=0; i<s.size(); i++){
        if(i>k-1){break;}
        else if(s[i]!='1'){std::cout << s[i] << "\n"; return 0;}
    }
    std::cout << 1 << "\n";
    return 0;
}
