#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> h(n);
    for(int i = 0; i < n; i++) std::cin >> h[i];
    std::sort(h.begin(), h.end());

    int ans = 2000000000;
    for(int i = 0; i + k - 1 < n; i++){
        int minH = h[i];
        int maxH = h[i + k - 1];
        ans = std::min(ans, maxH - minH);
    }
    std::cout << ans << std::endl;
    return 0;
}
