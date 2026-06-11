#include<iostream>
#include<vector>
#include<string>

int main(){
    std::string S;
    std::cin >> S;

    // 先頭が白
    int white_cost = 0;
    for(int i = 0; i < S.size(); i++){
        if(i % 2 == 0){
            if(S[i] != '1') white_cost++;
        }else{
            if(S[i] != '0') white_cost++;
        }
    }

    // 先頭が黒
    int black_cost = 0;
    for(int i = 0; i < S.size(); i++){
        if(i % 2 == 0){
            if(S[i] != '0') black_cost++;
        }else{
            if(S[i] != '1') black_cost++;
        }
    }

    std::cout << std::min(white_cost, black_cost) << std::endl;
    return 0;
}
