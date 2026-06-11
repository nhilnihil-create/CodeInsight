#include <bits/stdc++.h>
using namespace std;

int main() {
    int D;
    cin >> D;
    int cnt = 25-D;
    string res="Christmas";
    for (int i=0; i<cnt; i++) {
        res = res + " Eve";
    }
    cout << res << "\n";
}