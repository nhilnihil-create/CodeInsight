#include <bits/stdc++.h>
 
typedef long long ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;
 
using namespace std;
 
int ans = 0;
ll goal;
 
bool is (ll a) {
    int f[3] = {0, 0, 0};
 
    string s = to_string(a);
    rep(i, s.length()) {
        if (s[i] == '3') f[0] = 1;
        if (s[i] == '5') f[1] = 1;
        if (s[i] == '7') f[2] = 1;
    }
    
    return f[0] && f[1] && f[2];
}
 
void dfs(ll now) {
 
    if (now > goal) return;
 
    if (now > 100 && now <= goal) {
        if (is(now)) {
          //  cout << now << endl;
            ans++;
        }
    }
 
    dfs(now * 10 + 3);
    dfs(now * 10 + 5);
    dfs(now * 10 + 7);
}
 
int main() {
 
    cin >> goal;
 
    dfs(3);
    dfs(5);
    dfs(7);
 
    cout << ans << endl;
}