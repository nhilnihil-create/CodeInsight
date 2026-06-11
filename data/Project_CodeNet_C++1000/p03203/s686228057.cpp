#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

using pint = pair<int,int>;

int main() {
    int H, W, N;
    map<int, set<int> > ma;
    cin >> H >> W >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        ma[x].insert(y);
    }
    int res = H;
    int left = 1, right = 1;
    for (int x = 2; x <= H; ++x) {
        if (!ma.count(x))  right = min(right + 1, W);
        else {
            int first = *ma[x].begin();
            if (left <= first && first <= right) {
                res = min(res, x - 1);
                break;
            }
            if (first != right + 1) right = min(right + 1, W);
        }
    }
    cout << res << endl;
}