#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

vi G[MAX_N];
vi par[MAX_N];
int ans[MAX_N][2];

int main() {
    int n,m;
    cin >> n >> m;

    rep(i,n-1+m){
        int a_,b_;
        cin >> a_ >> b_;
        G[a_].push_back(b_);
        par[b_].push_back(a_);
    }

    rep(i,MAX_N){
        ans[i][0] = -1;
        ans[i][1] = -1;
    }
    int root = -1;
    srep(i,1,n+1){
        if(par[i].size()==0){
            root = i;
            break;
        }
    }
    queue<P> que;
    ans[root][0] = 0;
    ans[root][1] = 0;
    rep(i,G[root].size()){
        que.push(P(G[root][i],1));
    }
    while(que.size()){
        P p = que.front();
        que.pop();
        if(ans[p.first][0]!=-1)continue;
        int continue_flag = 0;
        rep(i,par[p.first].size()){
            if(ans[par[p.first][i]][1] == -1){
                continue_flag = 1;
                break;
            }
        }
        if(continue_flag)continue;

        rep(i,par[p.first].size()){
            if(ans[par[p.first][i]][1]+1 > ans[p.first][1]){
                ans[p.first][0] = par[p.first][i];
                ans[p.first][1] = ans[par[p.first][i]][1]+1;
            }
        }
        if(ans[p.first][0]!=-1){
            rep(i,G[p.first].size()){
                que.push(P(G[p.first][i], p.second+1));
            }
        }
    }
    
    srep(i,1,n+1){
        cout << ans[i][0] << endl;
    }

    return 0;
}
 
 
