#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
vector<ll> x(100010);
vector<bool> used(100010);
vector<P> V[100010];
void dfs(int t){
    if(used[t])return;
    used[t] = true;
    for(auto p:V[t]){
        if(used[p.first]){
            if(x[t] + p.second != x[p.first]){
                //cout << t << " " << x[t] << " " << p.second << " " << x[p.first] << endl;
                cout << "No" << endl;
                exit(0);
            }
        }else{
            x[p.first] = x[t] + p.second;
            dfs(p.first);
        }
    }
    
}
main(){
    int N,M;
    cin >> N >> M;
    rep(i,0,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        V[a].push_back(P(b,c));
        V[b].push_back(P(a,-c));
    }
    rep(i,0,N){
        if(!used[i])dfs(i);
    }
    cout << "Yes" << endl;
}