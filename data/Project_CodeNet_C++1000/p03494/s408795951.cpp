#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    int  ans      = 0;
    bool is_break = false;
    while (true) {
        for (auto& a : A) {
            if (a % 2 != 0) {
                is_break = true;
                break;
            }
            a /= 2;
        }
        if (is_break) { break; }
        ++ans;
    }
    cout << ans << endl;
}
