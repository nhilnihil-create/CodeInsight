#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int r;
    cin >> r;
    if (r < 1200) {
        cout << "ABC" << endl;
        return 0;
    }
    if (r < 2800) {
        cout << "ARC" << endl;
        return 0;
    }
    cout << "AGC" << endl;
    return 0;
}