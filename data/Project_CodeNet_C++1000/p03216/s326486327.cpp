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
    int n, q;
    string s;
    cin >> n >> s >> q;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        int l = 0, r = 0;
        ll d = 0, m = 0, dm = 0, ans = 0;
        while(r != n){
            r++;
            if(r-l > k){
                if(s[l] == 'D') d--, dm-=m;
                else if(s[l] == 'M') m--;
                l++;
            }
            if(s[r-1] == 'D') d++;
            else if(s[r-1] == 'M') m++, dm += d;
            else if(s[r-1] == 'C') ans += dm;
        }
        cout << ans << "\n";
    }
    return 0;
}
