#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    if (count(s.begin(), s.end(), 'R') >
        count(s.begin(), s.end(), 'B')) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
