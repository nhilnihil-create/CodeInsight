#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll =long long;
ll n;
vector<pair<ll,ll> >e;
vector<ll>size;
map<ll,ll>mp;
int main(){
    ll tmp;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&tmp);
        mp[tmp]=i;
        e.push_back(make_pair(tmp,i));   
    }
    sort(e.rbegin(),e.rend());
    vector<pair<ll,ll>>ans;
    vector<ll>size(n,1);
    vector<ll>dp(n,0);
    ll x = e.back().first;
    for(auto c:e){
        if(c.first!=x){
            if(size[c.second]*2>=n){
                cout<<"-1";
                return 0;
            }
            ll pre = c.first - n + 2 * size[c.second];
            if(!mp.count(pre)){
                cout<<"-1";
                return 0;
            }
            ll par = mp[pre];
            dp[par] += dp[c.second] + size[c.second];
            size[par] += size[c.second];
            ans.push_back(make_pair(c.second+1,par+1));
        }
    }
     if(dp[e.back().second]!=x){
        cout<<"-1";
        return 0;
    }
    for(auto c: ans){
        if(c.second < c.first)cout<<c.second <<' '<<c.first<<endl;
        else cout<<c.first <<' '<<c.second <<endl;
    }
    return 0;
}