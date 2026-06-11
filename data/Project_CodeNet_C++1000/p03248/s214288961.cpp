//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)

int main() {
    string s;
    cin >> s;
    if (s.back() == '1') {
        cout << -1 << endl;
        return 0;
    }
    s.pop_back();
    rep(i,0,s.size()/2) {
        if (s[i] != s[s.size()-1-i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (s[0] == '0') {
        cout << -1 << endl;
        return 0;
    }
    rep(i,s.size()/2+(s.size()%2),s.size()) {
        s[i] = '0';
    }
    ll last = 0;
    rep(i,0,s.size()) {
        ll a = last;
        ll b = i+1;
        cout << a+1 << " " << b+1 << endl;
        if (s[i] == '1') {
            last = b;
        }
    }
}