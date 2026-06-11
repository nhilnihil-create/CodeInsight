#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') cnt++;
    }

    if (cnt >= n / 2 + 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;   
}