#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int d; cin >> d;
    string s = "Christmas";
    int n = 25 - d;
    for (int i = 0; i < n; i++) {
        s += " Eve";
    }
    cout << s << endl;
    return 0;
}