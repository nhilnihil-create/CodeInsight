#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (llong (Itr) = a; (Itr) < b; (Itr) += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

#include <iostream>
#include <map>
#include <vector>
using namespace std;
using llong = long long;


int main() {
    int n;
    vector<llong> a;
    cin >> n;
    a.resize(n);
    for (auto &vs:a) cin >> vs;

    map<llong, llong> mp;
    mp[0] = 1;

    llong ans = 0;
    llong s = 0;
    for (auto vs:a) {
        s += vs;
        ans += mp[s];
        mp[s]++;
    }

    cout << ans << endl;

    return 0;
};
