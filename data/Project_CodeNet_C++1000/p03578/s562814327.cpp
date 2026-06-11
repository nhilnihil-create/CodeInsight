#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n,m;
    std::cin >> n;
    std::multiset<int> d;
    rep(i,n){
        int di;
        std::cin >> di;
        d.insert(di);
    }

    std::cin >> m;
    rep(i,m){
        int ti;
        std::cin >> ti;
        if(d.find(ti)==d.end()){
            std::cout << "NO" << "\n";
            return 0;
        }else{
            d.erase(d.find(ti));
        }
    }
    std::cout << "YES" << "\n";
    return 0;
}