#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<int> x(m), d(m-1);
    rep(i,m) std::cin >> x[i];

    if(n>=m){
        std::cout << 0 << "\n";
        return 0;
    }

    std::sort(x.begin(), x.end());
    rep(i,m-1) d[i] = x[i+1] - x[i];
    std::sort(d.begin(),d.end());

    int ans = x.back() - x.front();
    rep(i,n-1){
        ans -= d[d.size()-1-i];
    }
    std::cout << ans << "\n";
    return 0;
}
