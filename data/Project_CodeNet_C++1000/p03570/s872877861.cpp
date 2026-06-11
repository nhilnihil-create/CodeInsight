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
    map<int, int> v;
    v[0] = 0;
    int k = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        k ^= (1 << (s[i]-'a'));
        int p = INF<int>;
        if(v.count(k)){
            p = min(p, v[k]+1);
        }
        for (int j = 0; j < 26; ++j) {
            int k2 = k ^ (1 << j);
            if(v.count(k2)){
                p = min(p, v[k2]+1);
            }
        }
        if(v.count(k)) v[k] = min(v[k], p);
        else v[k] = p;
        if(i+1 == s.size()){
            ans = p;
        }
    }
    cout << ans << "\n";
    return 0;
}
