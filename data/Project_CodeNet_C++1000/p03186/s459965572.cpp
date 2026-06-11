#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    if (B < C) {
        if (A < C - B) cout << B * 2 + A + 1 << endl;
        else cout << B + C << endl;
    } else {
        cout << B + C << endl;
    }
    return 0;
}
