#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    string s; 
    cin >> s;
    int ans = 0;
    int l = 0, r = s.size() -1;
    while (l < r) {
        if (s[l] == s[r]) {
            ++l; --r;
            continue;
        }
        if (s[l] == 'x') {
            ++l;
            ++ans;
            continue;
        }
        if (s[r] == 'x') {
            --r;
            ++ans;
            continue;
        }
        ans = -1;
        break;
    }
    cout << ans << endl;
    return 0;
}