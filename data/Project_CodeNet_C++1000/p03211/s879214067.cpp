#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;
    int ret = 2000; // 753-xより十分大きい
    for (int i = 0; i <= x.size()-2; i++) {
        int tmp = stoi(x.substr(i,3));
        ret = min(abs(tmp-753), ret);
    }
    cout << ret << endl;
    return 0;
}