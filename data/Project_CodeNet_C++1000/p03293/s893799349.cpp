#include <iostream>

int main(void){
    std::string S, T, ans="No";
    std::cin >> S >> T;
    int N = S.size();

    for (int i=0; i<N; ++i){
        bool flg = true;
        int loc = i;
        for (int j=0; j<N; ++j){
            if (loc + j >= N) loc -= N;
            if (S.at(loc + j) != T.at(j)){
                flg = false;
                break;
            }
        }
        if (flg){
            ans = "Yes";
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
