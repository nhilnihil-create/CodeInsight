#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    map<ll,int>mp;
    int n;cin >>n;
    for (int i = 0; i < n; ++i) {
        ll d;cin >>d;
        mp[d]++;
    }
    int m;cin >>m;
    bool flg=true;
    for (int i = 0; i < m; ++i) {
        int t;cin >>t;
        if(mp[t]>0)mp[t]--;
        else {
            flg=false;
            break;
        }
    }
    if(flg)puts("YES");
    else puts("NO");
}

