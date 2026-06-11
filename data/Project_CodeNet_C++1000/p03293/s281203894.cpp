#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s, t;
    cin >> s >> t;
    queue<char> sq, tq;
    for (int i = 0; i < (int)s.size(); i++) {
        sq.push(s.at(i));
        tq.push(t.at(i));
    }
    for (int i = 0; i < (int)s.size(); i++) {
        sq.push(sq.front());
        sq.pop();
        if (sq == tq) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}