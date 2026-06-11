#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int x = i * 4 + j * 7;

            if (x == N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
