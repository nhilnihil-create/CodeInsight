#include <iostream>
#include <vector>

int main(void){
    int n, m, c, ans=0;
    std::cin >> n >> m >> c;
    std::vector<int> b(m);
    for (int i=0; i<m; ++i) std::cin >> b.at(i);

    for (int i=0; i<n; ++i){
        int cnt = 0;
        for (int j=0; j<m; ++j) {
            int tmp;
            std::cin >> tmp;
            cnt += b.at(j) * tmp;
        }
        if (cnt > -c) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}