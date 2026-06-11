#include <iostream>
#include <stdlib.h>
#include <math.h>

int main(){
    std::string S;
    std::cin >> S;
    int l = sizeof(S);
    int maxlen = 0;
    int curlen = 0;
    for (int i = 0; i < l; i++) {
        if (S[i] == 'A' || S[i] == 'T' || S[i] == 'C' || S[i] == 'G') {
            curlen++;
        } else {
            if (curlen > maxlen) maxlen = curlen;
            curlen = 0;
        }
    }
    std::cout << maxlen << std::endl;
    return 0;
}