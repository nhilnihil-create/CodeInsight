#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    int maxVal = 0;
    for (int i = 1; i < N; i++) {
        string prevS = S.substr(0, i);
        string latterS = S.substr(i, N - i);

        int count = 0, pos;
        for (char alphabet : alphabets) {
            pos = prevS.find(alphabet);
            bool prevShas = (pos == -1) ? false : true;
            pos = latterS.find(alphabet);
            bool latterShas = (pos == -1) ? false : true;
            if (prevShas && latterShas) count++;
        }
        maxVal = max(maxVal, count);
    }

    cout << maxVal << endl;

    return 0;
}
