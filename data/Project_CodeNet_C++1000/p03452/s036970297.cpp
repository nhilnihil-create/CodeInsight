#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
int MOD = 1000000007;

using namespace std;

vector<vector<pair<int,int>>> P(100001);
int used[100001] = {0};
int d[100001];
int ans = 1;

int dfs(int now){
    if(used[now] == 1) return 0;

    used[now] = 1;
    for(auto x : P[now]){
        if(d[x.fi] == INF){
            d[x.fi] = d[now] + x.se; dfs(x.fi);
        }else if(d[x.fi] != d[now] + x.se){
                ans = 0;
        }     
    }

}

signed main(){
    
    int n,m; 
    cin >> n >> m;

    REP(i,100001) d[i] = INF;

    REP(i,m){
        int a,b,c;
        cin >> a >> b >> c;

        P[a].pb(MP(b,c));
        P[b].pb(MP(a,-1*c));
    }

    for(int i = 1; i <= n;i++){
        if(used[i] == 1 || P[i].size() == 0){

        }else{
            d[i] = 0;
            dfs(i);
        }
    }

    if(ans == 1) cout << "Yes" << endl;
    else cout << "No" << endl;



    return 0;
}
//g++ -std=c++14 code1.cpp