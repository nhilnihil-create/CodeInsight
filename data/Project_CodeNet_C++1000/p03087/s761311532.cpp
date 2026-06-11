#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define rad2deg(a) ((a)/M_PI * 180.0)
#define deg2rad(a) ((a)/180.0 * M_PI)
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    int n,q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<std::pair<int,int>> lr(q);
    rep(i,q){
        std::cin >> lr[i].first >> lr[i].second;
        lr[i].first--;
        lr[i].second--;
    }

    std::vector<int> ac(n+1,0);
    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='A'&&s[i+1]=='C') ac[i+1]=ac[i]+1;
        else ac[i+1]=ac[i];
    }

    rep(i,q) std::cout << ac[lr[i].second] - ac[lr[i].first] << "\n";
    return 0;
}
