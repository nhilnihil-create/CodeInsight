#include <bits/stdc++.h>
using namespace std;

long long solve(string S) {
    int res = 0;
    for (int i = 0, j = S.size() - 1; i < j; ) {
        if (S[i] == S[j]) ++i, --j;
        else if (S[i] == 'x') ++res, ++i;
        else if (S[j] == 'x') ++res, --j;
        else return -1;
    }
    return res;
}

int main() {
    string S;
    while (cin >> S) cout << solve(S) << endl;
}