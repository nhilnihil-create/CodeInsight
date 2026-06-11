#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
//const int mod= int(1e9)+7;
const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    ll n,k;cin >>n>>k;
    ll now=1;
    for (int i = 0; i < n; ++i) {
        now=min(now+k,now*2);
    }
    cout <<now<<endl;
}

