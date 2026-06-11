#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
const std::string yes = "Yes";
const std::string no  = "No";

int solve(int x){
    int y = 0;
    while(x%100==0){
        x /= 100;
        y++;
    }
    return y;
}

int main(){
    int d,n;
    std::cin >> d >> n;
    int cnt=0,ans=0;
    while(cnt<n){
        ans++;
        if(solve(ans)==d) cnt++;
    }
    std::cout << ans << "\n";
    return 0;
}
