#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using ll = long long;
using p = std::pair<ll, ll>; // 円, 本数

int main(){
    ll n, m;
    std::cin >> n >> m;
    std::vector<p> goods(n);
    for(int i = 0; i < n; i++){
        std::cin >> goods[i].first >> goods[i].second;
    }
    std::sort(goods.begin(), goods.end());

    ll num = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(num + goods[i].second >= m){
            ans += (m - num) * goods[i].first;
            break;
        }else{
            num += goods[i].second;
            ans += goods[i].first * goods[i].second;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
