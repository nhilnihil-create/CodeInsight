#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    string S; cin >> S;
    int cnt = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] != 'A' && S[i] != 'C' && S[i] != 'G' && S[i] != 'T') continue;
        int k = 0;
        for (int j = i; i < S.length(); ++j) {
            if (S[j] != 'A' && S[j] != 'C' && S[j] != 'G' && S[j] != 'T') {
                k = j; break;
            }
        }
        cnt = max(cnt, k - i);
    }
    printf("%d\n", cnt);
}
