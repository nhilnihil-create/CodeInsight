#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    if(s.size()==1)  { cout << s << endl; return 0;}
    char ans;
    ll cnt = 0;
    rep(i,s.size()){
        if(s[i]!='1') {ans = s[i]; break;}
        else cnt++;
    }
    if(cnt >= k) cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}