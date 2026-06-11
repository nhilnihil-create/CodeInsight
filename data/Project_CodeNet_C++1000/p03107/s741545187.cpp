#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 100000000;

int main() {
    string S;
    int cnt1 = 0;
    int cnt2 = 0;
    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') {
            cnt1++;
        } else {
            cnt2++;
        }
    }

    cout << 2 * min(cnt1, cnt2) << endl;
}
