#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
struct xydata {
    int x, y;
};

bool cmp1 (const xydata &left, const xydata &right) {
    return left.y > right.y;
}
bool cmp2 (const xydata &left, const xydata &right) {
    return left.x < right.x;
}

int main() {
    cin >> n;
    vector<xydata> red;
    vector<xydata> blue;
    for(int i = 0; i < n; ++i) {
        xydata r;
        cin >> r.x >> r.y;
        red.push_back(r);
    }
    for(int i = 0; i < n; ++i) {
        xydata b;
        cin >> b.x >> b.y;
        blue.push_back(b);
    }

    sort(red.begin(), red.end(), cmp1);
    sort(blue.begin(), blue.end(), cmp2);

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int cbx = blue.at(i).x;
        int cby = blue.at(i).y;

        for(int j = 0; j < n; ++j) {
            if(red.at(j).x < cbx) {
                if(red.at(j).y < cby) {
                    ans++;
                    red.at(j).x = red.at(j).y = 10000;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}