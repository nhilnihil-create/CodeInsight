#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    map<string, bool> dic;
    char b;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (dic[s]) {
            cout << "No" << endl;
            return 0;
        } else dic[s] = true;
        if (i > 0) {
            if (b != s.at(0)) {
                cout << "No" << endl;
                return 0;
            }
        }
        b = s.at(s.size()-1);
    }
    cout << "Yes" << endl;
}