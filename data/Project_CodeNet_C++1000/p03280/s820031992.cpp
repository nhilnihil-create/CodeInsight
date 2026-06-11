#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 100010;

int main() {
    int a, b; cin >> a >> b;
    int area = a * b - (a + b - 1);
    cout << area << endl;
    return 0;
}