/**
*    created: 29.06.2020 18:26:01
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int mod = 1000000007;
const long double pi = acos(-1.0);
const int inf = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = -1;
    
    for (int i = 1; i <= n-1; i++) {
        map<char,int> mp1;
        map<char,int> mp2;
        string s1 = s.substr(0,i);
        string s2 = s.substr(i,n-i+1);
        rep(j,s1.size()) mp1[s1[j]]++;
        rep(j,s2.size()) mp2[s2[j]]++;
        int cnt = 0;
        for (auto p : mp1) if (p.second > 0 && mp2[p.first] > 0) cnt++;
        chmax(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}