#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using ll = long long;
const ll INF = 100000000000000;

int main(){
    ll n;
    std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        a[i] -= i + 1;
    }

    std::sort(a.begin(), a.end());

    // 中央値でOK
    ll b = a[n / 2];
    ll out = 0;
    for(int i = 0; i < n; i++){
        out += std::abs(a[i] - b);
    }

    std::cout << out << std::endl;

    return 0;
}
