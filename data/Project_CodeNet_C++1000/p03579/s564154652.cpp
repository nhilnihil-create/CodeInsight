#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;

#define MAX_N 200005
vector<int> G[MAX_N];
int f[MAX_N];
int BipartiteGraph(){
    rep(i,MAX_N)f[i] = -1;
    queue<int> que;
    que.push(0);
    f[0] = 0;
    int flag = 0;
    while(que.size() > 0){
        int x = que.front();
        que.pop();
        rep(i,G[x].size()){
            if(f[G[x][i]] == -1){
                f[G[x][i]] = (f[x] + 1) % 2;
                que.push(G[x][i]);
            }else{
                if(f[G[x][i]] == f[x]){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)break;
    }
    if(flag == 1) return -1;
    int res = 0;
    rep(i,MAX_N){
        if(f[i] == 0)res++;
    }
    return res;
}

int main() {
    ll n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll count = BipartiteGraph();
    ll ans = 0;
    if(count == -1){
        ans = n * (n - 1) / 2 - m;
    }else{
        ans = count * (n - count) - m;
    }

    cout << ans << endl;
    return 0;
}
 
 
