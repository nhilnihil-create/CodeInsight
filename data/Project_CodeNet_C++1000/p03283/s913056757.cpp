#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,m,Q;cin >>n>>m>>Q;
    vector<vector<ll>> a(n,vector<ll>(n,0));
    for (int i = 0; i <m ; ++i) {
        ll l ,r;cin >>l>>r;
        l--;r--;
        a[l][r]++;
    }
    vector<vector<ll>>s(n+1,vector<ll>(n+1,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
        }
    }
    for (int i = 0; i <Q ; ++i) {
        ll p,q;cin >>p>>q;
        p--;
        cout <<s[q][q]-s[p][q]-s[q][p]+s[p][p]<<endl;
    }
    return 0;
}