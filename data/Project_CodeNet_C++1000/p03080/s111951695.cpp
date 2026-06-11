#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    int red = 0;
    int blue = 0;
    rep(i, N) {
        if (S[i] == 'R') ++red;
        if (S[i] == 'B') ++blue;
    }
    
    if (red > blue) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
