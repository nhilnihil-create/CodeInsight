#include <bits/stdc++.h>
using namespace std;

int main() {
    string N; cin >> N;
    for (int i = 1; i < N.size(); i++) {
        if (N.at(i) == '9') continue;
        else {
            cout << 9 * (N.size() - 1) + N.at(0) - '0' - 1 << endl;
            return 0;
        }
    }
    cout << 9 * (N.size() - 1) + N.at(0) - '0' << endl;
}