#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    string s; cin >> s;
    int l = 0, r = s.length()-1;
    int ans = 0;
    while(r - l != 0 && r > l){
        bool lx = s[l] == 'x';
        bool rx = s[r] == 'x';
        if(s[l] != s[r]){
            if(lx) {
                l++;
                ans++;
            }else if(rx){
                r--;
                ans++;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }else{
            l++; r--;
        }
    }
    cout << ans << endl;
    return 0;
}
