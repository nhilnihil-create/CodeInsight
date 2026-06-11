#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;
typedef pair<int,int> pr;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    ll n; cin >> n;
    ll b = 0, w = 0;
    ll ans = 10000000;
    string s;cin >> s;

    rep(i,s.length()){
        if(s[i] == '.') w ++;
        else b ++;
    }
    ans = min(b,w);
    b = 0;

    rep(i,s.length()){
        if(s[i] == '.') w --;
        else b ++;

        ans = min(ans,b+w);
    }

    cout << ans;
}