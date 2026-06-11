#include <bits/stdc++.h>

int main(){
    std::string S, T;
    std::cin >> S >> T;
    std::vector< char > char_chg_S(26, 0);
    std::vector< char > char_chg_T(26, 0);
    
    std::string S_chg;
    char index = 'a';
    for(int i=0; i<S.size(); i++){
        if(char_chg_S[S[i] - 'a'] == 0 && char_chg_T[T[i] - 'a'] == 0){
            char_chg_S[S[i] - 'a'] = index;
            char_chg_T[T[i] - 'a'] = index;
            index++;
        }else if(char_chg_S[S[i] - 'a'] != char_chg_T[T[i] - 'a']){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    
    std::cout << "Yes" << std::endl;
    
    return 0;
}

