#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;
string s;

int main(void){
    cin >> n >> s;
    lli W, B, w, b;
    W = B = 0;
    rep(i, n){
        if(s[i] == '.')W++;
        else B++;
    }

    w = b = 0;
    lli ans = W;
    rep(i, n){
        if(s[i] == '.') w++;
        else b++;
        ans = min(ans, b+W-w);
    }
    cout << ans << endl;
    return 0;
}
