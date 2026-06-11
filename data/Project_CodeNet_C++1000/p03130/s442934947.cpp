#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
#include <numeric>
using namespace std;

#define INF 1e18
#define int long long

template<typename T>
void printVec(vector<T> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

signed main() {
    vector<vector<int>> v(4, vector<int> (4, 0));
    for(int i = 0; i < 3; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        v[a][b] = 1;
        v[b][a] = 1;
    }

    int odd = 0;
    for(int i = 0; i < 4; i++) {
        int d = 0;
        for(int j = 0; j < 4; j++) {
            if(v[i][j]) d++;
        }
        if(d % 2 != 0) odd++;
    }

    if(odd == 0) {
        cout << "YES" << endl;
        return 0;
    }

    cout << (odd == 2 ? "YES" : "NO") << endl;
    return 0;
}
