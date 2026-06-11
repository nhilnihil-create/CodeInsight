#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++) 
#define ltype int
#define rep(i,j,k) for(ltype (i)=(j);(i)<=(k);(i)++)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
const int inf=0x3f3f3f3f,
mod=1000000007;
const double pi=3.1415926535897932,
eps=1e-6;
int n,ans,p1,p2;
pii s[100005];
priority_queue<pii > a,b;bool tk[100005];
ll work(bool lft){
    while(!a.empty()) a.pop();while(!b.empty()) b.pop();
    rep(i,1,n){
        a.push(mpr(-s[i].se,i));
        b.push(mpr(s[i].fi,i));
        tk[i]=0;
    }
    ll res=0;int cur=0;
    while(1){
        if(lft){
            while(!a.empty()&&tk[a.top().se]) a.pop();
            if(a.empty()) break;
            int nxt=-a.top().fi;
            if(nxt<=cur) res+=cur-nxt,cur=nxt,tk[a.top().se]=1;
            else break;
        }
        else {
            while(!b.empty()&&tk[b.top().se]) b.pop();
            if(b.empty()) break;
            int nxt=b.top().fi;
            if(cur<=nxt) res+=nxt-cur,cur=nxt,tk[b.top().se]=1;
            else break;
        }
        lft^=1;
    }
    res+=abs(cur);
    return res;
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&s[i].fi,&s[i].se);
    int cur=0;
    ll ans=max(work(0),work(1));
    printf("%lld",ans);
    return 0;
}