#include<iostream>
#include<vector>
#include<string>
#include<set>

int main(){
    std::string S;
    int K;
    std::cin >> S >> K;
    
    // 長さは高々Kなのでそこまで調べれば十分
    std::set<std::string> st;
    for(int i = 0; i < S.size(); i++){
        for(int length = 1; length <= K; length++){
            if(i + length - 1 >= S.size()) continue;
            st.insert(S.substr(i, length));
        }
    }

    auto iter = st.begin();
    for(int i = 0; i < K - 1; i++) iter++;
    std::cout << *iter << std::endl;
    
    return 0;
}
