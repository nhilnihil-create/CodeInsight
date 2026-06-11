#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

bool isUpper(char c) {
    return 'A' <= c && c <= 'Z';
}

bool isLower(char c) {
    return 'a' <= c && c <= 'z';
}

int main() {
    string S; cin >> S;
    int N = S.size();

    if (S[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    int cnt = 0;
    int index = -1;
    for (int i = 2; i <= N - 2; i++) {
        if (S[i] == 'C') {
            cnt++;
            index = i;
        }
    }
    if (cnt != 1) {
        cout << "WA" << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) continue;
        if (i == index) continue;

        if (!isLower(S[i])) {
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "AC" << endl;
}
