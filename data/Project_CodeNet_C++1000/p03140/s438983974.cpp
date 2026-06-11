#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    int ans = 0;
    rep(i, n) {
        if ( sa[i] == sb[i] && sb[i] == sc[i] ) continue;
        if ( sa[i] != sb[i] && sb[i] != sc[i] && sc[i] != sa[i] ) {
            ans += 2;
            continue;
        }
        if ( sa[i] != sb[i] && sa[i] != sc[i] && sb[i] == sc[i] ||
             sb[i] != sc[i] && sb[i] != sa[i] && sc[i] == sa[i] ||
             sc[i] != sa[i] && sc[i] != sb[i] && sa[i] == sb[i] ) {
            ans += 1;
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}
