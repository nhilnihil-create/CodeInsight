#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
vector<int> enum_div(int n){
    vector<int> ret;
for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}
int main(){
    ll n,m;cin>>n>>m;
    vector<int> s;
    ll ans=0;
    s=enum_div(m);
    sort(all(s),greater<int>());
    ll a[n];
    bool ok=false;
    rep(i,s.size()){
        if(m%s[i]==0&&m/s[i]>=n){
            ok=true;
            ans=s[i];
            break;
    }
}
if(ok)cout << ans << endl;
}