#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;

int main() {
    char A, B; cin >> A >> B;
    if (A < B) {
        cout << "<" << endl;
    } else if (A == B) {
        cout << "=" << endl;
    } else {
        cout << ">" << endl;
    }
    return 0;
}