#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <iomanip>
#include <deque>
#include <queue>
#include <unordered_map>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <sstream>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll pow(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = pow(N, P/2);
        return t*t;
    }
    return N * pow(N, P-1);
}
ll modpow(ll N, ll P,ll k){
    if(P==0) return 1;
    if(P%2==0){
        ll t = modpow(N, P/2,k)%k;
        return t*t%k;
    }
    return N * modpow(N, P-1,k)%k;
}
ll modkai(ll n,ll m,ll k){//n*(n-1)*(n-2)*...(m+1)%k
    if(n == m)return 1;
    return modkai(n-1,m,k)*n%k;
}
ll mod_cnb(ll n,ll m,ll k){//nCm%k,kは十分大きい素数
  int m_=modkai(m,0,k);
  return modkai(n,n-m,k)*modpow(m_,k-2,k)%k;
}
ll gcd(ll n,ll m){
    ll n_ = max(n,m);
    ll m_ = min(n,m);
    if(n_%m_ == 0)return m_;
    return gcd(m_,n_%m_);
}
ll lcm(ll n,ll m){
    return n*m/gcd(n,m);
}

int main() {
    ll h,w;cin>>h>>w;
    vector<vector<int>>a(h,vector<int>(w));
    rep(i,h){
        rep(j,w)cin>>a[i][j];
    }
    int cnt=0;
    vector<vector<int>> ans;
    rep(i,h){
       rep(j,w-1){
           if(a[i][j]%2==0)continue;
           cnt++;
           vector<int>v;
           a[i][j]--;
           a[i][j+1]++;
           v.push_back(i);
           v.push_back(j);
           v.push_back(i);
           v.push_back(j+1);
           ans.push_back(v);
       }
    }
    rep(i,h-1){
        if(a[i][w-1]%2==0)continue;
        cnt++;
        vector<int>v;
        a[i][w-1]--;
        a[i+1][w-1]++;
        v.push_back(i);
        v.push_back(w-1);
        v.push_back(i+1);
        v.push_back(w-1);
        ans.push_back(v);
    }
    cout<<cnt<<endl;
    rep(i,ans.size()){
        rep(j,3)cout<<ans[i][j]+1<<" ";
        cout<<ans[i][3]+1<<endl;
    }

}