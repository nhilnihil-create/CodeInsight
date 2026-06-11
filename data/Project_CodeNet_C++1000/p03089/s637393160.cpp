#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int n;
vector<int> b;

vector<int> rec(vector<int> d) {
    for (int i = d.size()-1;i >= 0;i--) {
        if (d[i] == i+1) {
            d.erase(d.begin()+i);
            auto k = rec(d);
            d.insert(d.begin()+i, i+1);
            if (k.size() == d.size() - 1) {
                k.push_back(i+1);
                return k;
            } else {
                return vector<int>();
            }
        }
    }
    return vector<int>();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        b.push_back(c);
    }
    auto k = rec(b);
    for (auto e:k) cout << e << endl;
    if (k.size() == 0) cout << -1 << endl;
    return 0;
}
