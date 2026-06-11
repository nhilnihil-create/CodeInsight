#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> x(n), origin(n);
    for(int i = 0; i < n; i++){
        std::cin >> x[i];
        origin[i] = x[i];
    }

    std::sort(x.begin(), x.end());

    int middle = (n - 2) / 2;
    for(int i = 0; i < n; i++){
        auto iter = std::lower_bound(x.begin(), x.end(), origin[i]);
        int pos = std::distance(x.begin(), iter);
        if(pos > middle){
            std::cout << x[middle] << std::endl;
        }else{
            std::cout << x[middle + 1] << std::endl;
        }
    }
    return 0;
}
