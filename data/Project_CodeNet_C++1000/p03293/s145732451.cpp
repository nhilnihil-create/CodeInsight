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

int main() {
    string S, T; cin >> S >> T;
    int N = S.size();

    bool ok = false;
    for (int i = 0; i < N; i++) {
        swap(S[0], S[N - 1]);
        for (int j = N - 1; j >= 2; j--) {
            swap(S[j], S[j - 1]);
        }

        if (S == T) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
