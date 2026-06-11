#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> parts(3, std::vector<int>(n));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++) std::cin >> parts[i][j];
        std::sort(parts[i].begin(), parts[i].end());
    }

    long long cnt = 0;
    for(int i = 0; i < n; i++){
        // まず真ん中の段を決める
        int b = parts[1][i];
        auto a_iter = std::lower_bound(parts[0].begin(), parts[0].end(), b);
        auto c_iter = std::upper_bound(parts[2].begin(), parts[2].end(), b);
        cnt += std::distance(parts[0].begin(), a_iter) * std::distance(c_iter, parts[2].end());
    }

    std::cout << cnt << std::endl;
    
    return 0;
}
