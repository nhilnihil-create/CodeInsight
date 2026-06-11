#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int win = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (c == 'o')
            win++;

    }
    win = win + (15 - s.size());

    cout << ((win >= 8) ? "YES" : "NO") << endl;
}