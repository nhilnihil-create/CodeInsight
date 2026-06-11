#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    lli ans = 1e18;
    rep(i, n+1){
        lli s, t, c;
        s = i;
        t = n-i;
        c = 0;
        while(t > 0) c+=t%6, t/=6;
        while(s > 0) c+=s%9, s/=9;
        ans = min(ans, c);
    }
    cout << ans << endl;
    return 0;
}
