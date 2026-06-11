#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    ll m,a,r,c,h;
    m = a = r = c = h = 0;
    int n;
    cin >> n;
    rep(i,n) {
        string s;
        cin >> s;
        if(s[0] == 'M') {
            m++;
        } else if(s[0] == 'A') {
            a++;
        } else if(s[0] == 'R') {
            r++;
        } else if(s[0] == 'C') {
            c++;
        } else if(s[0] == 'H') {
            h++;
        }
    }
    ll ans = 0;
    ans += (m*a*r + m*a*c + m*a*h + m*r*c + m*r*h + m*c*h + a*r*c + a*r*h + a*c*h + r*c*h);
    cout << ans << "\n";
    return 0;
}