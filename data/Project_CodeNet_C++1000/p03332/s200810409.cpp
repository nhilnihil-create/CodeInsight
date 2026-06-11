#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdio>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>()>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
#define mp make_pair
using namespace std;
int in(){int x;scanf("%d",&x);return x;}
string stin(){string s;cin>>s;return s;}
ll lin(){ll x;scanf("%lld",&x);return x;}
ll mod=998244353;
vecll perm;
ll pw(ll a,ll p){
    if(p==0)return 1;
    if(p%2==0){
        ll d=pw(a,p/2);
        return d*d%mod;
    }
    return a*pw(a,p-1)%mod;
}
ll divide(ll a,ll b){
    return a*(ll)pw(b,mod-2)%mod;
}
ll n;
ll comb(ll a,ll b){
    return divide(perm[a],perm[b]*perm[a-b]%mod);
}
int main(){
    n=in();ll a=in(),b=in(),k=lin(),ans=0;
    perm=vecll(n+1);
    perm[0]=1;
    rep2(i,1,n){
        perm[i]=perm[i-1]*i%mod;
    }
    ll x=0;
    while(a*x<=k&x<=n){
        if((k-x*a)%b==0){
            ll y=(k-x*a)/b;
            if(0<=y&y<=n)ans=(ans+comb(n,x)*comb(n,y)%mod)%mod;
        }
        x++;
    }
    cout<<ans<<endl;
}