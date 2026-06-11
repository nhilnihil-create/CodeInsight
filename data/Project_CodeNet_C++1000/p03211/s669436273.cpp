#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    int div = 1000;
    int T;
    for(int i=0; i < s.size()-2; i++) {
        t = s.substr(i, 3);
        T = stoi(t);
        div = min(abs(753-T), div);
    }
    cout << div << endl;
}

