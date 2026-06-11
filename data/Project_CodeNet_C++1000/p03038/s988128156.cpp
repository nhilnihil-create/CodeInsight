#include<iostream>
#include<vector>
#include<algorithm>
int main(void){
    int n, m;
    std::cin >> n >> m;
    std::vector<long long > a(n);
    std::vector<std::pair<long long ,long long >> bc(m);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        int b, c;
        std::cin >> b >> c;
        bc[i] = std::make_pair(c, b);
    }
    std::sort(bc.rbegin(), bc.rend());
    std::sort(a.begin(), a.end());
    int ai = 0;
    int bi = 0;
    int cnt = 0;
    long long ans = 0;
    while(ai < n){
        if(cnt == bc[bi].second){
            cnt = 0;
            bi++;
        }
        if(a[ai] < bc[bi].first){
            ans += bc[bi].first - a[ai];
            cnt++;
        }else{
            break;
        }
        ai++;
    }
    for(int i = 0; i < n; i++){
        ans += a[i];
    }
    std::cout << ans << std::endl;
    return 0;
}