#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    long long K;
    cin >> S;
    cin >> K;

    long long num1st1 = 0;
    long long the1stNon1 = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '1') {
            ++num1st1;
        }
        else {
            the1stNon1 = S[i] - '0';
            break;
        }
    }

    if (K <= num1st1) {
        cout << 1 << endl;
    }
    else {
        cout << the1stNon1 << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
