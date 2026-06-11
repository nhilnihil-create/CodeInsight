#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    int pre_x = 0, pre_y = 0, pre_t = 0;
    for(int i = 0; i < n; i++){
        int t, x, y;
        std::cin >> t >> x >> y;

        int need_t = t - pre_t, need_x = std::abs(x - pre_x), need_y = std::abs(y - pre_y);
        if(need_x + need_y > need_t){
            std::cout << "No" << std::endl;
            return 0;
        }else{
            int diff = need_t - (need_x + need_y);
            if(diff % 2 != 0){
                std::cout << "No" << std::endl;
                return 0;
            }
        }

        pre_x = x, pre_y = y, pre_t = t;
    }

    std::cout << "Yes" << std::endl;
    return 0;
}
