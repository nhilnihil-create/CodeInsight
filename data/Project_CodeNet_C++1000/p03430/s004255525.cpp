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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=924844033;
#define N 1055050

ll n,m,k;
string s;
vector<vec> mm(300,vec(1,-1));
vector<vector<vec>> mem(300,vector<vec>(300,vec(300,-1)));
int dfs(int l,int r,int c){
    if(c>k)return -2;
    if(l>r)return 0;
    if(l==r)return 1;
    if(mem[l][r][c]!=-1) return mem[l][r][c];
    if(s[l]==s[r]){
        return mem[l][r][c]=2+dfs(l+1,r-1,c);
    }
    int count=0;
    count=max(dfs(l+1,r,c),count);
    count=max(count,dfs(l,r-1,c));
    count=max(count,dfs(l+1,r-1,c+1)+2);
    return mem[l][r][c]=count;
}

main(){
    cin>>s;
    n=s.size();
    k=in();
    cout<<dfs(0,n-1,0);
    
}
