#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> vp(M);
    vector<int> vy(M);
    map<int, vector<int>> m;
    rep(i, M) {
        cin >> vp[i];
        cin >> vy[i];
        m[vp[i]].push_back(vy[i]);
    }

    for(auto& itr: m) {
        sort(itr.second.begin(), itr.second.end());
    } 

    int P, Y;
    rep(i, M) {
        P = vp[i];
        Y = vy[i];
        auto it = lower_bound(m[P].begin(), m[P].end(), Y);
        auto ret = (it - m[P].begin()) + 1;
        printf("%06d%06d\n", P, (int)ret);

    }

    return 0;
}

