#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

// ref : https://img.atcoder.jp/arc101/editorial.pdf
using ll = long long;

int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<ll> x(n);
    for(int i = 0; i < n; i++){
        std::cin >> x[i];
    }


    // n - k + 1通りを全探索
    ll minCost = (x[n - 1] - x[0]) * 2;
    for(int start = 0; start <= n - k; start++){
        int l = start;
        int r = start + k - 1;
        ll cost = std::min(std::abs(x[l]), std::abs(x[r])) + std::abs(x[l] - x[r]);
        minCost = std::min(cost, minCost);
    }

    std::cout << minCost << std::endl;
    return 0;
}
