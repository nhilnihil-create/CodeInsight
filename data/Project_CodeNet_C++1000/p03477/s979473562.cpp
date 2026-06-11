#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    if (A + B > C + D) cout << "Left" << endl;
    else if (A + B < C + D) cout << "Right" << endl;
    else cout << "Balanced" << endl;
}