#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    string s;
    cin >> n >> s;
    set<char> s1;
    size_t ans = 0;
    rep(i, n-1){
        s1.insert(s[i]);
        set<char> e(begin(s)+i+1, end(s));
        set<char> result;
        set_intersection(s1.begin(), s1.end(), e.begin(), e.end(), inserter(result, result.end()));
        ans = max(result.size(), ans);
    }

    cout << ans << endl;

    return 0;
}
