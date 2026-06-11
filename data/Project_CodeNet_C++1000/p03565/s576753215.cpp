#include<iostream>
#include<vector>
#include<string>
#include<set>

int main(){
    std::string S, T;
    std::cin >> S >> T;
    std::vector<int> possible;
    std::set<std::string> st;

    
    for(int i = 0; i < S.size() - T.size() + 1; i++){
        // i startでTを作れるか調査
        int j;
        for(j = 0; j < T.size(); j++){
            if(S[i + j] != '?' && S[i + j] != T[j]) break;
        }

        if(j == T.size()) possible.push_back(i);
    }

    // 作れない
    if(possible.empty()){
        std::cout << "UNRESTORABLE" << std::endl;
        return 0;
    }
    // 各候補点から辞書順で最小のものを作る
    for(int i = 0; i < possible.size(); i++){
        std::string out = S;
        for(int j = 0; j < T.size(); j++){
            out[j + possible[i]] = T[j];
        }

        // ?の場所をaで埋める
        for(int i = 0; i < out.size(); i++){
            if(out[i] == '?') out[i] = 'a';
        }

        st.insert(out);
    }

    for(auto s : st){
        std::cout << s << std::endl;
        return 0;
    }
    
    return 0;
}
