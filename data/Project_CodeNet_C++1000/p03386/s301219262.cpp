#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<bool> flag(b-a+1, false);
    for (int i = 0; i < k; i++) {
        flag[i] = true;
    }
    for (int i = flag.size()-k; i < flag.size(); i++) {
        flag[i] = true;
    }

    for (int i = 0; i < flag.size(); i++) {
        if (flag[i])
            cout << a+i << endl;
    }
}