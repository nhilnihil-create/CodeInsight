#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

int main(){
    std::string S, T;
    std::cin >> S >> T;
    std::unordered_set<char> Sset, Tset;
    for(int i = 0; i < S.size(); i++){
        Sset.insert(S[i]);
        Tset.insert(T[i]);
    }

    if(Sset.size() == Tset.size()){
        // 同じ文字は相手も同じでないとだめ
        std::vector<std::vector<int>> same(26);
        for(int i = 0; i < S.size(); i++) same[S[i] - 'a'].push_back(i);
        for(int i = 0; i < 26; i++){
            if(same[i].size() == 0) continue;
            std::unordered_set<char> tmp;
            for(int j = 0; j < same[i].size(); j++){
                tmp.insert(T[same[i][j]]);
            }
            if(tmp.size() != 1){
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }else{
        std::cout << "No" << std::endl;
        return 0;
    }

    std::cout << "Yes" << std::endl;
    return 0;
}
