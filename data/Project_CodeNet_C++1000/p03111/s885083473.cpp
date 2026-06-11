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
    int n;cin>>n;
    int x[3];cin>>x[0]>>x[1]>>x[2];
    vector<int>l(n);
    rep(i,n)cin>>l[i];
    
    int mp=1e9;
    for(int i=0;i<(1<<2*n);i++){
        //cout<<i<<endl;
        bool f[3];
        vector<vector<int>>v(3);
        f[0]=f[1]=f[2]=0;
        rep(j,n){
            int target=(i&(3<<(j*2)))>>(j*2);
            if(target==3)continue;
            v[target].push_back(l[j]);
            f[target]=1;
        }
        if(!(f[0]&&f[1]&&f[2]))continue;
        int mpp=0;
        rep(j,3){
            mpp+=v[j].size()*10-10;
            int sum=0;
            rep(k,v[j].size())sum+=v[j][k];
            mpp+=abs(x[j]-sum);
        }
        mp=min(mp,mpp);
    }
    cout<<mp<<endl;
}