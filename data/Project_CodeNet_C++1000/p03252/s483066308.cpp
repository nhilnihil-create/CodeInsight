/**
*    created: 24.06.2020 14:04:35
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    
    map<int,int> mp;
    rep(i,s.size()) {
        int s1 = s[i] - 'a' + 1;
        int t1 = t[i] - 'a' + 1;
        if (mp[s1] == 0) mp[s1] = t1;
        else if (mp[s1] == t1) continue;
        else if (mp[s1] != t1) {
            cout << "No" << endl;
            return 0;
        }
    }
    map<int,int> mp1;
    for (auto p : mp) {
        if (mp1[p.second] == 0)  mp1[p.second] = p.first;
        else if (mp1[p.second] == p.first) continue;
        else if (mp1[p.second] != p.first) {
            cout << "No" << endl;
            return 0;
        }   
    }
    cout << "Yes" << endl;
    return 0;
}