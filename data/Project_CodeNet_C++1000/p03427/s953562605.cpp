#include <iostream>
#include <string>

int main(void){
    int N, ans=0;
    std::string S;
    std::cin >> S;
    N = S.size();

    if (N == 1){
        ans = stoi(S);
    } else if (S.at(0) != '9'){
        bool flg = true;
        for (int i=1; i<N; ++i){
            if (S.at(i) != '9'){
                flg = false;
                break;
            }
        }
        if (flg) ++ans;
        ans += (int)S.at(0) - '1';
        ans += 9 * (N - 1);
    } else {
        for (int i=0; i<N; ++i){
            if (S.at(i) == '9'){
                ans += 9;
            } else {
                ans += 9 * (N - i) - 1;
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
