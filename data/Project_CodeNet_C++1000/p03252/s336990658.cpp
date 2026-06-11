#include<iostream>
#include<vector>
#include<string>
#include<map>

// ref : https://drken1215.hatenablog.com/entry/2018/09/23/232100

int main(){
    std::string S, T;
    std::cin >> S >> T;
    std::map<char, char> transform, invTransform;
    for(int i = 0; i < S.size(); i++){
        char s = S[i], t = T[i];
        if(transform.count(s)){
            if(transform[s] != t){
                std::cout << "No" << std::endl;
                return 0;
            }
        }
        if(invTransform[t]){
            if(invTransform[t] != s){
                std::cout << "No" << std::endl;
                return 0;
            }
        }
        transform[s] = t, invTransform[t] = s;
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
