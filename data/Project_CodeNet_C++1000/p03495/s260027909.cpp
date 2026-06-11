#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<int> count(N, 0);

    for (int i = 0; i < N; i++) {
        count.at(A.at(i) - 1)++;
    }
    sort(count.begin(), count.end());
    int type = 0;
    for(int i = 0; i < N; i++) {
        if (count.at(i) > 0) type++;
    }
    int res = 0;
    for(int i = 0; i < N; i++) {
        if (type <= K) break;
        if (count.at(i) > 0) {
            res += count.at(i);
            type--;
        }
    }
    cout << res << endl;
}
