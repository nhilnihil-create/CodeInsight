#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long T = 0, c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        for (int j = 0; j + 1 < S.size(); ++j) {
            if (S[j] == 'A' && S[j + 1] == 'B') ++T;
        }
        if (S[0] == 'B' && S.back() == 'A') ++c1;
        else if (S.back() == 'A') ++c2;
        else if (S[0] == 'B') ++c3;
    }
    if (c2 == 0 && c3 == 0) cout << T + max(c1 - 1, 0LL) << endl;
    else cout << T + c1 + min(c2, c3) << endl;
}