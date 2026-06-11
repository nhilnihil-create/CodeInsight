#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nr = count(s.begin(), s.end(), 'R');
    int nb = n - nr;
    if (nr > nb) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

