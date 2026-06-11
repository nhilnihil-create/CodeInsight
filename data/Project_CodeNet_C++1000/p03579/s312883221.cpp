#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int long long
typedef long long ll;
 
int color[200000];
 
int n,m;
vector<vector<int>> v(200000);
 
bool dfs(int nn, int pre, int c){
    for(auto x:v[nn]){
        if(x==pre) continue;
        if(color[x]==color[nn]) return false;
        if(color[x]!=color[nn] && color[x]!=-1) continue;
        if(color[x]==-1) color[x]=1-c;
        if(!dfs(x,nn,color[x])) return false;
    }
 
    return true;
}
 
 
signed main(){
    cin >> n >>m;
    memset(color,-1,sizeof(color));
    rep(i,m){
        int aa,bb;
        cin >> aa >> bb;
        v[aa-1].push_back(bb-1);
        v[bb-1].push_back(aa-1);
    }
    //rep(i,n) cout << color[i] << endl;
    color[0]=0;
    if(dfs(0,-1,0)){
        int white=0;
        int black=0;
        rep(i,n){
            if(color[i]==0) white++;
            else black++;
        }
        cout << white*black-m << endl;
    }
    else cout << (n*(n-1)/2)-m << endl;
 
    
 
 
}