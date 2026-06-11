#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    bool j1 = true, j2 = false, j3 = true, j4 = false;
    int cp = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (i == 0 && S[i] != 'A') j1 = false;
        if (2 <= i && i <= S.length() - 2 && S[i] == 'C') {
            if (j4 == false) j2 = true, j4 = true, cp = i;
            else j2 = false;
        }
        if (i != 0 && i != cp && 'A' <= S[i] && S[i] <= 'Z') j3 = false;
    }
    if (j1 && j2 && j3) printf("%s\n", "AC");
    else printf("%s\n", "WA");
}
