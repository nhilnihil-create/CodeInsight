#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    int n;cin >>n;
    Vl a(n);
    ll mx=0;
    ll mn=-1;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        if(abs(mx)<=abs(a[i])){
            mx=a[i];
            mn=i;
        }
    }
    vector<P>ans;
    for (int i = 0; i < n; ++i) {
        ans.push_back({i,mn});//+1
    }
    if(mx>=0){
        for (int i = 1; i < n; ++i) {
            ans.push_back({i,i-1});
        }
    }
    else {
        for (int i = n-1; i>0; --i) {
            ans.push_back({i-1,i});
        }
    }
    ll m=ans.size();
    cout <<m<<endl;
    for (int i = 0; i < m; ++i) {
        cout <<ans[i].second+1<<" "<<ans[i].first+1<<endl;
    }
}
