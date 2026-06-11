#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m; cin >>n >>m;
    map<int, int> ab{};
    for (int i = 0; i < n; i++) {
        int k, v;
        cin >>k >>v;
        auto it = ab.find(k);
        if (it != ab.end()) {
            v += it->second;
            ab.erase(k);
        }
        ab.insert(make_pair(k,v));
    }
    long long ret = 0;
    for (auto const& i : ab) {
        if (m>i.second) {
            ret += (long long) i.first * i.second;
            m -= i.second;
        }
        else {
            ret += (long long) i.first * m;
            m = 0;
        }
        if (m == 0) break;
    }
    cout << ret << endl;
    return 0;
}