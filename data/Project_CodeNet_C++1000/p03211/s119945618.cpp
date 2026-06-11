#include <bits/stdc++.h>
using namespace std;

int sevenFiftyThree(string s) {
    int minimum = 1e5;
    for (int i = 0; i <= s.length() - 3; i++) {
        int Ss = stoi(s.substr(i, 3));
        minimum = min(minimum, abs(Ss - 753));
    }
    return minimum;
}

int main() {
    string S; cin >> S;
    cout << sevenFiftyThree(S) << endl;
}