//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    vector<vector<pp>> path(n);
    vector<int> ans(n,-1);
    rep(i,n-1){
        int a,b,w; cin>>a>>b>>w;
        a--; b--;
        path[a].push_back(mk(b,w));
        path[b].push_back(mk(a,w));
    }
    queue<pp> que;
    que.push(mk(0,-1));
    ans[0]=1;
    int s,from;
    while(!(que.empty())){
        tie(s,from)=que.front();
        que.pop();
        for(auto to:path[s]){
            if(to.first==from) continue;
            que.push(mk(to.first,s));
            ans[to.first]=(ans[s]+to.second)%2;
        }
    }
    rep(i,n) printf("%d\n",ans[i]);
}
