#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int main() {
    string s; cin >> s;
    int n = s.size();

    int red = 0; int blue = 0;
    REP(i, n) {
        if (s[i] == '0') ++red;
        else ++blue;
    }

    cout << min(red, blue) * 2 << endl;

    return 0;
}