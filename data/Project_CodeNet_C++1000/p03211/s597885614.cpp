#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    string S; cin >> S; int diff = 10e7;
    for (int i = 0; i < S.length(); ++i) {
        string w = S.substr(i, 3);
        int n = stoi(w);
        if (diff > abs(753 - n)) diff = abs(753 - n);
    }
    printf("%d\n", diff);
}
