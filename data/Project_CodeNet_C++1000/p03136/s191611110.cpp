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
    int n;cin >>n;
    V l(n);
    int sum=0;
    int mx=-1;
    for (int i = 0; i < n; ++i) {
        cin >>l[i];
        mx=max(mx,l[i]);
        sum+=l[i];
    }
    sum-=mx;
    if(mx<sum)puts("Yes");
    else puts("No");
}

