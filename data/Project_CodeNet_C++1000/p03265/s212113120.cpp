#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 100010;

struct Point {
    int x, y;
};

int main() {
    vector<Point> p(4);
    for (int i = 0; i < 2; i++) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 2; i < 4; i++) {
        p[i].x = p[i - 1].x - (p[i - 1].y - p[i - 2].y);
        p[i].y = p[i - 1].y + (p[i - 1].x - p[i - 2].x);
        cout << p[i].x << " " << p[i].y << " ";
    }
    cout << endl;
    return 0;
}