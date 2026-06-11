#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    bool ok = (S[0] =='A');
    int cnt = 0, N = S.size();
    for (int i = 1; i < N; i++) {
        if (2 <= i && i <= N - 2 && S[i] == 'C') cnt++;
        else if (S[i] < 'a' || 'z' < S[i]) ok = false;
    }

    if (ok && cnt == 1) cout << "AC" << endl;
    else cout << "WA" << endl;
}