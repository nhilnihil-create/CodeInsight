#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
    int N, K;
    std::cin >> N >> K;

    std::vector<int> kinds(N); // max N kinds

    int num_kinds = 0;

    for(int i = 0; i < N; i++){
        int a;
        std::cin >> a;
        if(kinds.at(a-1) == 0) num_kinds++; // new kind
        kinds.at(a-1)++;
    }
    /*
    for(int i = 0; i < N; i++){
        std::cout << " " << kinds.at(i);
    }
    std::cout << std::endl;
    std::cout << "kinds=" << num_kinds << std::endl;
    */
    std::sort(kinds.begin(), kinds.end());
    int rest = num_kinds - K;
    int i = 0;
    int ans = 0;
    while(rest > 0){
        if(kinds.at(i) > 0){
            ans += kinds.at(i);
            rest--;
        }
        i++;
    }

    std::cout << ans << std::endl;    
}
