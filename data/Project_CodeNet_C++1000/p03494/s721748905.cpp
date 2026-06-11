#include <bits/stdc++.h>

using namespace std;

const int N = 202;
int a[N];

bool check(int n) {
    bool is = true;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            is = false;
            break;
        }
    }
    return is;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    while (check(n)) {
//        bool is = true;
//        for (int i = 0; i < n; i++) {
//            if (a[i] % 2 == 1) {
//                is = false;
//                break;
//            }
//        }
//        if (!is) break;
        res++;
        for (int i = 0; i < n; i++) {
            a[i] /= 2;
        }
    }
    cout << res;
    return 0;
}