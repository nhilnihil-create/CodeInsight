#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int A, B, K;
    std::cin >> A >> B >> K;
    std::vector<int> C;

    for (int i=0; i<K; ++i){
        int a = A + i;
        int b = B - i;
        if (a < b) {
            C.emplace_back(a);
            C.emplace_back(b);
        } else if (a == b){
            C.emplace_back(a);
        } else {
            break;
        }
    }

    std::sort(C.begin(), C.end());

    for (int i: C){
        std::cout << i << std::endl;
    }

    return 0;
}
