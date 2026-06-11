#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

struct UnionFind{
    vector<int>par;

    UnionFind(int n) : par(n){
        rep(i,n)par[i] = i;
    }

    int root(int x){
        if(par[x]==x)return x;
        return par[x] = root(par[x]);
    }

    void unite(int x,int y){
        if(root(x)==root(y))return;
        par[root(x)] = root(y);
    }

    bool same(int x,int y){
        return root(x)==root(y);
    }
};




int main(){
   int a,b,c;cin>>a>>b>>c;
   vector<ll>s(a),t(b);
   rep(i,a)cin>>s[i];
   rep(i,b)cin>>t[i];

   rep(ii,c){
       ll now;cin>>now;
       vector<ll>ss(2,INF*INF),tt(2,INF*INF);
       if(now == *lower_bound(ALL(s),now))ss[0] = now;
       else {
           ll id = lower_bound(ALL(s),now)-s.begin();
           if(id-1>=0)ss[0] = s[id-1];
           if(id<s.size())ss[1] = s[id];
       }
       if(now == *lower_bound(ALL(t),now))tt[0] = now;
       else {
           ll id = lower_bound(ALL(t),now)-t.begin();
           if(id-1>=0)tt[0] = t[id-1];
           if(id<t.size())tt[1] = t[id];
       }

       ll res = INF*INF;
       rep(i,2){
           ll dist;
           rep(j,2){
               dist = abs(now-ss[i])+abs(ss[i]-tt[j]);
               res = min(res,dist);
           }
       }
       rep(i,2){
           ll dist;
           rep(j,2){
               dist = abs(now-tt[i])+abs(tt[i]-ss[j]);
               res = min(res,dist);
           }
       }
       cout<<res<<endl;
   }
}

