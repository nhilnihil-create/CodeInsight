#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    long long K; cin >> S >> K;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '1' && K != 1) {
            K--;
        } else {
            cout << S.at(i) << endl;
            return 0;
        }
    }
}