#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define rad2deg(a) ((a)/M_PI * 180.0)
#define deg2rad(a) ((a)/180.0 * M_PI)
const std::string yes = "Yes";
const std::string no  = "No";

int solve(int n){
    int ret=0;
    while(n>0){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main(){
    int n,a,b;
    std::cin >> n >> a >> b;

    int ans = 0;
    for(int i=1; i<=n; i++){
        int buf = solve(i);
        if(a<=buf && buf<=b) ans += i;
    }
    std::cout << ans << "\n";
    return 0;
}
