#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    long long K;
    cin >> S >> K;

    int i = 0;
    while (S[i] == '1') i++;

    if (i < K) cout << S[i] << endl;
    else cout << 1 << endl;
}