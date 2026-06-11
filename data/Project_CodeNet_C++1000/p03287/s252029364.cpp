#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n,m;cin >>n>>m;
    vector<int>a(n);
    ll ans=0;
    unordered_map<ll,int>mp;
    ll sum=0;
    mp[0]++;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        a[i]%=m;
        sum+=a[i];
        sum%=m;
        ans+=mp[sum];
        mp[sum]++;
    }
    cout <<ans <<endl;
}