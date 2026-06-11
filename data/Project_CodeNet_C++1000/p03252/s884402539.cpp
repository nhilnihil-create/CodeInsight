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
    string s, t;
    cin >> s >> t;
    map<char, vector<int>> m1;
    map<char, vector<int>> m2;

    rep(i, s.size()) {
        m1[s[i]].push_back(i);
        m2[t[i]].push_back(i);
    }

#if 0
    for(auto itr: m1) {
        cout << itr.first << " [";
        for(auto n : itr.second)
           cout  << n << ",";
        cout << "]" << endl;
    }

    for(auto itr: m2) {
        cout << itr.first << " [";
        for(auto n : itr.second)
           cout  << n << ",";
        cout << "]" << endl;
    }
#endif
    rep(i, s.size()) {
        if(m1[s[i]].empty())
            continue;
        if(m1[s[i]] != m2[t[i]]) {
            cout << "No" << endl;
            return 0;
        }
        m1.erase(s[i]);
        m2.erase(t[i]);
#if 0
        cout << i << endl;
        for(auto n : m1[s[i]])
           cout << " " << n << ",";
        cout << endl;
        for(auto n : m2[t[i]])
           cout << " "  << n << ",";
        cout << endl;
#endif
    }
    cout << "Yes" << endl;

    return 0;
}

