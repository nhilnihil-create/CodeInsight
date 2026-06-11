#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

struct DATA {
    Int p;
    Int y;
    Int id;
    bool operator< (const DATA& d) const {
        if (p < d.p) {
            return true;
        } else if (p == d.p && y < d.y) {
            return true;
        } else {
            return false;
        }
    }
};

int main(void) {
    Int n, m;
    cin >> n >> m;
    Int p, y;
    vector<DATA> v(m);
    for (Int i = 0; i < m; ++i) {
        cin >> p >> y;
        v[i] = {--p, y, i};
    }
    sort(v.begin(), v.end());

    Int k = 0;
    map<Int, string> mp;
    for (Int i = 0; i < n; ++i) {
        Int j;
        for (j = k; j < m; ++j) {
            if (v[j].p == i) {
                mp[v[j].id] = to_string(v[j].p + 1000001).substr(1, 6) + to_string((j - k + 1) + 1000000).substr(1, 6);
            } else {
                break;
            }
        }
        k = j;
    }
    for (Int i = 0; i < m; ++i) {
        cout << mp[i] << endl;
    }

    return 0;
}
