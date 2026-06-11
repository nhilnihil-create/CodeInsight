#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;
    int N = S.size();
    int nr = 0;
    int nb = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            ++nr;
        }
        else {
            ++nb;
        }
    }
    cout << min(nr, nb) * 2 << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
