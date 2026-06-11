#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    rep(i,n) std::cin >> a[i];

    int ans = 0;
    rep(i,n) ans += a[i] - 1;

    std::cout << ans << "\n";
    return 0;
}
