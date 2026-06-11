// 先頭か末尾に移動されない要素は、その順序関係が変わらず、間になにか挿入されることがないので、
// それらは連続していることがわかる。
// 昇順に+1の等差で並んだ、インデックスが昇順の順列の内最大のものを求める。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        Q[P[i]] = i;  // Q[i] := 数iがある配列Pのインデックス
    }
    vector<int> S(N + 1, 1);
    for (int i = 2; i <= N; ++i) {
        if (Q[i - 1] < Q[i]) {
            S[i] = S[i - 1] + 1;
        }
    }
    int continuous = 0;
    for (int i = 1; i <= N; ++i) {
        continuous = max(continuous, S[i]);
    }
    cout << N - continuous << endl;
    return 0;
}