#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    int cnt = 0;
    bool c = false;

    for (int i = 0, n = a + b + 1; i < n; i++)
        if (s.at(i) == '-') {
            cnt++;

            if (i == a)
                c = true;
        }

    cout << ((cnt == 1 && c) ? "Yes" : "No") << endl; 
}