#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    int n;
    cin >> n;
    int index[n + 1];
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        index[p] = i;
    }
    int M = 0;
    int now = 1;
    for (int i = 2; i <= n; i++) {
        if (index[i] > index[i - 1]) {
            now++;
        }
        else {
            if (M < now) {
                M = now;
            }
            now = 1;
        }
    }
    if (now > M) M = now;
    cout << n - M << endl;
    return 0;
}