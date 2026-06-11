#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<int> x1;
    vector<int> y1;
    vector<int> x2;
    vector<int> y2;
    rep(i, h) rep(j, w-1) {
        if ( a[i][j]&1 ) {
            x1.push_back(j), y1.push_back(i), x2.push_back(j+1), y2.push_back(i);
            ++a[i][j+1];
        }
    }
    rep(i, h-1) {
        if ( a[i][w-1]&1 ) {
            x1.push_back(w-1), y1.push_back(i), x2.push_back(w-1), y2.push_back(i+1);
            ++a[i+1][w-1];
        }
    }
    cout << x1.size() << endl;
    rep(i, x1.size()) {
        cout << y1[i]+1 << " " << x1[i]+1 << " " << y2[i]+1 << " " << x2[i]+1 << endl;
    }
    return 0;
}
