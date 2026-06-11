#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int valid = true;
    for (int i = 0; i+1 < n; ++i) {
        if(v[i] >= v[i+1]) valid = false;
    }
    if(valid) {
        puts("1");
        return 0;
    }
    int ng = 1, ok = n;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        deque<pair<int, int>> s;
        s.emplace_back(0, -INF<int>);
        for (int i = 1; i < n; ++i) {
            if(v[i-1] < v[i]) continue;
            while(s.back().first > v[i]) s.pop_back();
            if(s.back().first == v[i]){
                s.back().second++;
            }else {
                s.emplace_back(v[i], 1);
            }
            while(s.back().second == mid){
                int x = s.back().first;
                s.pop_back();
                if(s.back().first == x-1){
                    s.back().second++;
                }else {
                    s.emplace_back(x-1, 1);
                }
            }
        }
        if(s.front().second == -INF<int>) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
