#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (s[(i+j)%n] != t[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}