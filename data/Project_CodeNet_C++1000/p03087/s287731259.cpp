#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    // 累積和を求める
    vector<int> c(N + 1, 0);
    for (int i = 1; i < N; ++i) {
        int a = 0;
        if (S[i - 1] == 'A' && S[i] == 'C') a = 1;
        c[i + 1] = c[i] + a;
    }

    // 各クエリに答える
    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        --l;
        int result = c[r] - c[l];
        if (l > 0 && S[l - 1] == 'A' && S[l] == 'C') --result;
        cout << result << endl;
    }
}