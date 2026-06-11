#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    REP(_, N) {
        char S;
        cin >> S;
        if (S == 'Y') {
            cout << "Four" << endl;
            return 0;
        }
    }
    cout << "Three" << endl;

    return 0;
}
