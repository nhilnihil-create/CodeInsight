#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    rep(i,n) std::cin >> h[i];

    int ans = 0;
    while(std::accumulate(h.begin(),h.end(),0)){
        int cnt = 0;
        bool flag = false;
        for(int i=0; i<n; i++){
            if(h[i]==0){
                flag = false;
            }else if(flag==false){
                h[i]--;
                cnt++;
                flag = true;
            }else{
                h[i]--;
            }
        }
        ans += cnt;
    }
    std::cout << ans << "\n";
    return 0;
}