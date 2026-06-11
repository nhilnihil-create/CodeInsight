#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>l(n),r(n);
    int c = 0;
    rep(i,n){
        if(s[i]=='W')l[i] = ++c;
        else l[i] = c;
    }
    c = 0;
    for(int i = n-1;i>=0;--i){
        if(s[i]=='E')r[i] = ++c;
        else r[i] = c;
    }
    ll mini = INF;
    // rep(i,n){
    //     cout << l[i] << " ";
    // }
    // cout << endl;
    // rep(i,n){
    //     cout << r[i] << " ";
    // }
    // cout << endl;
    rep(i,n){
        ll cost = l[i] + r[i] -1;
        // cout << cost << endl;
        mini = min(cost,mini);
    }
    cout << mini << endl;
    return 0;
}