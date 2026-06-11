#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;

ll calC(ll a, ll b){

    if(a == 1) return 0;
    ll ans = 1;
    ll tmpB = b;
    ll tmpA = a;
    for(int i = 1; i <= b; i ++){
        ans *= tmpA;
        tmpA --;
    }
    for(int i = 1; i <= b; i ++){
        ans /= tmpB;
        tmpB --;
    }

    return ans;
}
int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> m(5);
    string s;
    rep(i,n) {
        cin >> s;
        if (s[0] == 'M') m[0]++;
        if (s[0] == 'A') m[1]++;
        if (s[0] == 'R') m[2]++;
        if (s[0] == 'C') m[3]++;
        if (s[0] == 'H') m[4]++;
    }

    ans += m[0]*m[1]*m[2];
    ans += m[0]*m[1]*m[3];
    ans += m[0]*m[1]*m[4];
    ans += m[0]*m[2]*m[3];
    ans += m[0]*m[2]*m[4];
    ans += m[0]*m[3]*m[4];
    ans += m[1]*m[2]*m[3];
    ans += m[1]*m[2]*m[4];
    ans += m[1]*m[3]*m[4];
    ans += m[2]*m[3]*m[4];

    cout << ans;

    return 0;
}
