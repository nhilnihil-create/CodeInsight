#include <iostream>
#include <vector>
int main(void){
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> check(m);
    std::vector<int> p(m);
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int num;
            std::cin >> num;
            check[i].push_back(num);
        }
    }
    for (int i = 0; i < m; i++) {
        std::cin >> p[i];
    }
    int ans = 0;
    for (int bit = 0; bit < (1<<n); bit++) {
        std::vector<int> switches(n);
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) switches[i] = 1;
            else switches[i] = 0;
        }
        bool flag = true;
        for (int i = 0; i < m; i++) {
            int check_sum = 0;
            for (int j = 0; j < check[i].size(); j++) {
                check_sum += switches[check[i][j] - 1];
            }
            if (check_sum % 2 != p[i]) flag = false;
        }
        if (flag) ans++;
    }
    
    std::cout << ans << std::endl;
    
    
}