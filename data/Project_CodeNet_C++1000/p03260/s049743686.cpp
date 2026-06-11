#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int a, b;
    cin >> a >> b;
    bool ans = false;
    for (int i = 1; i < 4; i++){
        if((a * b * i) % 2) ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
