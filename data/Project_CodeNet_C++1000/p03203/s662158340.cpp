#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int N=2e5+10;
vector<int> p[N];
int n,m,k,x,y,ps,ans;
inline bool check(int x,int y){
    if(p[x].empty()) return 1;
    vector<int>::iterator it=lower_bound(p[x].begin(),p[x].end(),y);
     return it==p[x].end()||*it!=y;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);ans=n;
    rep(i,1,k) scanf("%d%d",&x,&y),p[y].push_back(x);
    rep(i,1,n) sort(p[i].begin(),p[i].end());
    rep(i,1,n){
        ps++;while(!check(i,ps)) ++ps;
        vector<int>::iterator it=lower_bound(p[i].begin(),p[i].end(),ps);
        if(it!=p[i].end()) ans=min(ans,(*it)-1);
    }
    printf("%d\n",ans);
    return 0;
}