#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int bw = 0, wb = 0;
    for (int i = 0, n = s.size(); i < n; i++)
        if ((s.at(i) - '0') == (i % 2 == 0))
            bw++;
        else
            wb++;

    cout << min(bw, wb) << endl;
}