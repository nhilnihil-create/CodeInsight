#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto p : mp) {
        if(p.second > p.first) {
            ans += p.second - p.first;
        }
        else if(p.second < p.first) {
            ans += p.second;
        }
    }
    cout << ans << endl;
    return 0;
}
