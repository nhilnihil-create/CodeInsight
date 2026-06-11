//#define _XCODE_DEBUG

#include <iostream>
#include <string>

#ifdef _XCODE_DEBUG
    #include <fstream>
#endif

int main() {
    #ifdef _XCODE_DEBUG
        std::ifstream in("input.txt");
        std::cin.rdbuf(in.rdbuf());
    #endif
    
    std::string S, T;
    std::cin >> S >> T;
    int ls = (int)S.length();
    int lt = (int)T.length();
    
    std::string ans = "";
    for (int i=0; i<ls-lt+1; ++i) {
        std::string str = S;
        int c = 0;
        for (int j=0; j<lt; ++j) {
            if (S.substr(i+j,1)==T.substr(j,1)) {
                ++c;
            }
            else if (S.substr(i+j,1)=="?") {
                str.replace(i+j, 1, T.substr(j,1));
                ++c;
            }
            else {
                break;
            }
        }
        if (c==lt) {
            ans = str;
            for (int i=0; i<ls; ++i) {
                int ind = (int)ans.find("?");
                if (ind==std::string::npos) break;
                else ans.replace(ind, 1, "a");
            }
        }
    }
    if (ans.length()) std::cout << ans << "\n";
    else std::cout << "UNRESTORABLE" << "\n";
    return 0;
}