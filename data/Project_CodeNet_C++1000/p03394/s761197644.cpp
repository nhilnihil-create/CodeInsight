#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr double pi = asin(1) * 2;
constexpr ll mod = 1000000007;

template<class T>
class set2 : public set<T> {
private:
    typename set<T>::iterator back_itr() {
        auto e = this->end();
        e--;
        return e;
    }

public:
    T front() {
        if (this->empty()) throw;
        return *this->begin();
    }

    T back() {
        if (this->empty()) throw;
        return *this->back_itr();
    }

    void erase_front() {
        if (!this->empty()) this->erase(this->begin());
    }

    void erase_back() {
        if (!this->empty()) this->erase(this->back_itr());
    }
};

int main() {
    int n;
    cin >> n;
    char *w[3] = {(char *) "2 5 63", (char *) "2 5 20 63", (char *) "2 5 20 30 63"};
    if (n < 6) {
        cout << w[n - 3] << endl;
        return 0;
    }
    set<int> r;
    int v[4] = {2, 3, 4, 6}, s = 0;
    for (int i = 0; i < n; i++) r.insert((i / 4) * 6 + v[(i % 4)]);
    for (auto &e:r) s += e;
    int t = n / 4;
    if (s % 6 == 2) {
        r.insert((t + 1) * 6);
        r.erase(2);
    }
    if (s % 6 == 3) {
        r.insert((t + 1) * 6);
        r.erase(3);
    }
    if (s % 6 == 5) {
        r.insert(t * 6 + 4);
        r.erase(3);
    }
    for (auto &e:r) cout << e << ' ';
    cout << endl;
}