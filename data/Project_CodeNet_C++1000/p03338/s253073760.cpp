#include <iostream>
#include <algorithm>
#include <set>

int main(void){
    int N, ans = 0;
    std::string S;
    std::cin >> N >> S;

    for (int i = 1; i < N; ++i){
        std::set<char> lst, rst, st;
        std::string ls, rs;
        ls = S.substr(0, i);
        rs = S.substr(i, N - i);
        for (char c: ls){
            lst.insert(c);
        }
        for (char c: rs){
            rst.insert(c);
        }
        std::set_intersection(lst.begin(), lst.end(), rst.begin(), rst.end(), std::inserter(st, st.end()));
        ans = std::max(ans, (int)st.size());
    }

    std::cout << ans << std::endl;

    return 0;
}
