#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
vector<vector<int>> A(4);
bool ans  = false;
void dfs(int v,vector<int> count,int p){
    count[v] = 1;
    bool flag = false;
    rep(i,4){
        if(count[i]!=1){
            flag = true;break;
        }
    }
    if(flag){
        for(auto nv:A[v]){
            if(nv==p) continue;
            dfs(nv,count,v);
        }
    }else{
        ans = true;
        return;
    }
}
int main(){
   
    rep(i,3){
        int a,b;cin >> a >> b;
        a--,b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    for(int i=0;i<4;i++){
        vector<int> count(4);
        dfs(i,count,-1);
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}