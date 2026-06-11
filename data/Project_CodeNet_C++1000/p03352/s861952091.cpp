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
   ll x;cin >>x;
   ll mx=1;
    for (ll i = 2; i <=x; ++i) {
        ll k=i*i;
        while(k<=x){
            mx=max(mx,k);
            k*=i;
        }
    }
    cout <<mx<<endl;
}
