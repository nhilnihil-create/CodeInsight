#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    for (int i = 0; i < N; i++) {
        for (int j = i; j <= N; j++) {
            string str = S.substr(0, i) + S.substr(j);
            if (str == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}