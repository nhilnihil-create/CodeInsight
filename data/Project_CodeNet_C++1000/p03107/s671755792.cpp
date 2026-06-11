#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl = vector<ll>; using vvl = vector<vl>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main() {
    string s;cin >> s;
    ll a,b;a,b=0;
    rep(i,s.size()) {
        if(s[i]=='1') a++;
        else b++;
    }
    cout << 2*min(a,b) << endl;
}