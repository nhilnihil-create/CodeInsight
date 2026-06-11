#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    int minH = 1000;
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
        minH = std::min(minH, h[i]);
    }

    int cost = minH;
    for(int i = 0; i < n; i++) h[i] -= minH;
    // 区間が最大になるようにとる
    while(1){
        int left = 0, right = 0;
        int maxLeft = 0, maxRight = 0;
        for(int i = 0; i < n; i++){
            if(h[i] == 0){
                right = i;
                int tmpInterVal = right - left;
                int maxInterVal = maxRight - maxLeft;
                if(tmpInterVal > maxInterVal){
                    maxLeft = left, maxRight = right;
                }
                left = right + 1;
            }
        }
        // 最後用
        right = n;
        int tmpInterVal = right - left;
        int maxInterVal = maxRight - maxLeft;
        if(tmpInterVal > maxInterVal){
            maxLeft = left, maxRight = right;
        }

        // その区間の高さ最小
        int minH = 1000;
        for(int i = maxLeft; i < maxRight; i++){
            minH = std::min(minH, h[i]);
        }

        
        if(minH == 1000){
            break;
        }else{
            cost += minH;
            for(int i = maxLeft; i < maxRight; i++) h[i] -= minH;
        }
    }

    std::cout << cost << std::endl;
    return 0;
}
