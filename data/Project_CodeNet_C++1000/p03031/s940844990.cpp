#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<int> k(m);
    std::vector<int> s(m,0);
    std::vector<int> p(m);
    rep(i,m){
        std::cin >> k[i];
        rep(j,k[i]){
            int b;
            std::cin >> b; b--;
            s[i] += (1<<b);
        }
    }
    rep(i,m) std::cin >> p[i];


    int ans = 0;
    for(int bits=0; bits<(1<<n); bits++){
        int cnt = 0;
        for(int i=0; i<m; i++){
            int sum = 0;
            for(int j=0; j<n; j++){
                if(bits&(1<<j) && s[i]&(1<<j)) sum++;
            }
            if(sum%2==p[i]) cnt++;
        }
        if(cnt==m) ans++;
    }

    std::cout << ans << "\n";
    return 0;
}