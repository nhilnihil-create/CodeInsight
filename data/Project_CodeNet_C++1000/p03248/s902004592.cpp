#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define ld double
#define oo 2e18
#define OS tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    if (s[s.size() - 1] == '1' || s[0] == '0') {
        return cout << "-1\n", 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (s.size() - i - 2 >= 0 && s[s.size() - i - 2] != '1') {
                return cout << "-1\n", 0;
            }
        }
    }
    int last = s.size() - 1;
    for (int i = s.size() - 2; i >= 0; i--) {
        cout << i + 1 << " " << last + 1 << "\n";
        if (s[i] == '1') last = i;
    }
    return 0;
}