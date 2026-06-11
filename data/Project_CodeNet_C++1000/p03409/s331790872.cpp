#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<string>
#include<time.h>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

#define rep(i, n) for(int i = 0; i < (n); ++i)

using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    auto cmp = [](const P& a, const P& b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first > b.first;
    };
    auto cmp2 = [](const P& a, const P& b) {
        if (a.second == b.second) return a.first > b.first;
        else return a.second < b.second;
    };
    set<P, decltype(cmp)> rp(cmp);
    set<P, decltype(cmp2)> bp(cmp2);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        rp.insert(P(a, b));
    }
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        bp.insert(P(a, b));
    }
    int res = 0;
    for (auto itr = rp.begin(); itr != rp.end(); ++itr) {
        for (auto it = bp.lower_bound(*itr); it != bp.end(); ++it) {
            if (itr->first < it->first) {
                bp.erase(it);
                ++res;
                break;
            }
        }        
    }
    cout << res << endl;
    return 0;
}

