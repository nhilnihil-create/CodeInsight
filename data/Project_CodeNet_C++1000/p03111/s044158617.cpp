#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


//ABC 119 c
int n,a,b,c;
int ans = 1000000000;

void calc(vector<int> v,vector<int> l){
    int value[4] = {0,0,0,0};
    int count[4] = {-1,-1,-1,0};
    rep(i,n){
        value[v[i]] += l[i];
        
        count[v[i]]++;
    }

    if((count[0]+1)*(count[1]+1)*(count[2]+1)){
        int ans_cand = abs(a-value[0])+abs(b-value[1])+abs(c-value[2])+10*(count[0]+count[1]+count[2]);
        if(ans > ans_cand) ans = ans_cand;
    }
}

void dfs(int depth,vector<int> v,vector<int> l){
    if(depth==n) calc(v,l);
    else{
        for(int i = 0;i<4;i++){
            v[depth] = i;
            depth++;
            dfs(depth,v,l);
            depth--;
        }
    }
}




int main(){
    cin >> n >> a >> b >> c;
    vector<int> l(n),v(n);
    rep(i,n) cin >> l[i];
    v.assign(n+1,0);
    dfs(0,v,l);
    cout << ans << endl;
}


