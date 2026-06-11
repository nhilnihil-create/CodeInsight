#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    ll n,m;
    std::cin >> n >> m;
    std::vector<std::pair<ll,ll>> ab(n);
    rep(i,n){
        ll ai,bi;
        std::cin >> ai >> bi;
        ab[i] = std::make_pair(ai,bi);
    }

    std::sort(ab.begin(),ab.end());

    ll ans = 0, i=0;
    while(m>0){
        if(m > ab[i].second){
            m -= ab[i].second;
            ans += ab[i].first*ab[i].second;
            i++;
        }else{
            ans += ab[i].first*m;
            m = 0;
        }
    }
    std::cout << ans << "\n";
    return 0;
}