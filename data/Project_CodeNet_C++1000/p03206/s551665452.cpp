#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string ch = "Christmas";
    int d;
    cin >> d;
    for (int i = 0; i < 25 - d; i++) {
        ch += " Eve";
    }
    cout << ch;
    return 0;
}
