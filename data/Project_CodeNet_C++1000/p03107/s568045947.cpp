#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    std::string s;
    std::cin >> s;

    int n0=0, n1=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0') n0++;
        if(s[i]=='1') n1++;
    }

    std::cout << s.size()-abs(n1-n0) << "\n";
    return 0;
}
