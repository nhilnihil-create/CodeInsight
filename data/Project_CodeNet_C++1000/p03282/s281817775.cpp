#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    std::string S;
    ll K;
    std::cin >> S >> K;
    long double pos = 0.0;
    for(int i = 0; i < K; i++){
        if(S[i] != '1'){
            std::cout << S[i] << std::endl;
            return 0;
        }
    }

    std::cout << S[K - 1] << std::endl;

    return 0;
}
