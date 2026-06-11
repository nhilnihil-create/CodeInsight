#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    string S, T; cin >> S >> T;
    S += S;
    for (int i = 0; i < S.length() - T.length(); ++i) {
        string str = S.substr(i, T.length());
        if (str == T) {
            printf("%s\n", "Yes"); return 0;
        }
    }
    printf("%s\n", "No");
    return 0;
}
