#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define rad2deg(a) ((a)/M_PI * 180.0)
#define deg2rad(a) ((a)/180.0 * M_PI)
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(2,std::vector<int>(n+1,0));
    rep(i,n){int ai; std::cin >> ai; a[0][i+1]=a[0][i]+ai;}
    rep(i,n){int ai; std::cin >> ai; a[1][i+1]=a[1][i]+ai;}

    int ans = 0;
    rep(i,n){ans = std::max(ans,a[0][i+1]+a[1][n]-a[1][i]);}
    std::cout << ans << "\n";
    return 0;
}
