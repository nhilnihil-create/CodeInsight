#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A(5), P = { 0, 1, 2, 3, 4 };
    for (int i = 0; i < 5; i++) cin >> A.at(i);

    int fans = 1e5;
    do {
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            while (ans % 10 != 0) ans++;
            ans += A.at(P.at(i));
        }
        fans = min(fans, ans);
    } while (next_permutation(P.begin(), P.end()));
    cout << fans << endl;
}