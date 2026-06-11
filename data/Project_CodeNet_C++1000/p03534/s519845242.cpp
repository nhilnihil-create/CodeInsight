#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    vector<int> v(3, 0);
    for (auto &&i : s) {
        v[i - 'a']++;
    }
    auto n = s.length();
    for (auto &&j : v) {
        if(n/3 > j) {
            cout << "NO\n";
            return 0;
        }else {
            j -= n/3;
        }
    }
    if(max({v[0], v[1], v[2]}) == 2){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
