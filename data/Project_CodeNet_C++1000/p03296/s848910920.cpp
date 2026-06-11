// おなじ色で一列に並んだ個数をaとすると、その区間はa/2個色を変えればいいから、
// それぞれの区間のa/2を足す。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    int prev = -1;
    int len = 1;
    while (N--) {
        int a;
        cin >> a;
        if (a != prev) {
            prev = a;
            ans += len / 2;
            len = 1;
        } else {
            ++len;
        }
    }
    ans += len / 2;
    cout << ans << endl;
    return 0;
}