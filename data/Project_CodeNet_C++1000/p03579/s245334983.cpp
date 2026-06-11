#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 500000
ll MOD=1e9+7;
vector<vec> G(N,vec());
bool is_bi=true;
int visited[N];
void dfs(int x,int color){
    visited[x]=color;
    int next=color%2+1;
    for(auto e:G[x]){
        if(visited[e]&&visited[e]!=next)is_bi=false;
        if(visited[e]==0){
            dfs(e,next);
        }
    }
}
main(){
    ll n=in(),m=in();
    rep(i,m){
        int a=in(),b=in();
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1,1);
    ll nn=n*(n-1)/2;
    if(is_bi){
        ll ans=0;
        ll black=0,white=0;
        rep2(i,1,n){
            if(visited[i]==1)black++;
            else white++;
            for(auto e:G[i]){
                if(visited[e]!=visited[i])ans--;
            }
        }
        ans/=2;
        ans+=black*white;
        cout<<ans<<endl;
    }
    else{
        cout<<nn-m<<endl;
    }
    return 0;
}

