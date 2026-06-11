#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, k; cin >> n >> k;
    int cnt = 0;
    int tmp = 1;
    while (n--) {
        if (tmp  * 2 < tmp + k) {
            tmp *= 2;
        }
        else {
            tmp += k;
        }
    }
    cout << tmp << endl;
    return 0;
}