#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> x(m);
    for(int i = 0; i < m; i++){
        std::cin >> x[i];
    }

    std::sort(x.begin(), x.end());

    // 例外処理
    if(n >= m){
        std::cout << 0 << std::endl;
        return 0;
    }
    if(n == 1){
        std::cout << x[m - 1] - x[0] << std::endl;
        return 0;
    }

    // 区間を求める
    int ans = 0;
    std::vector<int> interval(m - 1);
    for(int i = 1; i < m; i++){
        interval.push_back(x[i] - x[i - 1]);
        ans += x[i] - x[i - 1];
    }

    
    std::sort(interval.begin(), interval.end(), std::greater<int>());
    for(int i = 0; i < n - 1; i ++){
        // 区間が大きいところから順に潰す
        ans -= interval[i];
    }

    std::cout << ans << std::endl;
            
    return 0;
}
