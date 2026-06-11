// 1-indexedで、i番目の要素は必ずi以上になる。なので、
// i < b[i] のとき、そのような数列は作れない
// そうでないなら、任意に作れそう？
// 逆順に見ると、挿入する数が一意に求まる
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> b(N);
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        --b[i];
    }
    vector<int> res;
    //for (auto p : b) cout << p << " ";
    //cout << endl;
    while (N) {
        int i = N - 1;
        while (i >= 0) {
            if (b[i] == i) break;
            --i;
        }
        if (i < 0) break;
        res.push_back(i);
        //cout << "i: " << i << " b[i]:" << b[i] << endl;
        b.erase(b.begin() + i);
        //for (auto p : b) cout << p << " ";
        //cout << endl;
        --N;
    }
    //cout << "N: " << N << endl;
    if (N > 0) {
        cout << -1 << endl;
    } else {
        for (int i = res.size() - 1; i >= 0; --i) {
            cout << res[i] + 1 << endl;
        }
    }
    return 0;
}