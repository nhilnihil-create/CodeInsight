#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    long long sum = 0;
    int pre = 0, next = 0;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        sum += std::abs(a[i] - pre);
        pre = a[i];
    }
    // 最後自宅に戻るぶん
    sum += std::abs(pre - next);

    for(int i = 0; i < n; i++){
        if(i == 0){
            pre = 0;
            next = a[i + 1];
        }else if(i == n - 1){
            pre = a[i - 1];
            next = 0;
        }else{
            pre = a[i - 1];
            next = a[i + 1];
        }
        long long tmp = sum;
        tmp -= std::abs(pre - a[i]) + std::abs(a[i] - next);
        tmp += std::abs(pre - next);
        std::cout << tmp << std::endl;
    }
    
    return 0;
}
