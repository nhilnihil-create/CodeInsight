#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string n;
    cin >> n;
    int tmp = 1;
    bool flag = false;
    for (int i = 1; i < 4; i++){
        if (n.at(i) == n.at(i - 1)) tmp++;
        else tmp = 1;
        if (tmp == 3) flag = true;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
