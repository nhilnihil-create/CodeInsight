#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    if ((A + B) > (C + D)) {
        cout << "Left" << endl;
    } else if ((A + B) < (C + D)) {
        cout << "Right" << endl;
    } else {
        cout << "Balanced" << endl;
    }
    return 0;
}