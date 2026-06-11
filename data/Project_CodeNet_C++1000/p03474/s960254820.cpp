#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B; string S; cin >> A >> B >> S;
    for (int i = 0; i < S.length(); ++i) {
        if (i != A) {
            if (S[i] == '-') {
                printf("%s\n", "No");
                return 0;
            }
        }
        else {
            if (S[i] != '-') {
                printf("%s\n", "No");
                return 0;
            }
        }
    }
    printf("%s\n", "Yes");
    return 0;
}
