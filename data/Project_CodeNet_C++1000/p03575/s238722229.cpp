#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int i, vector<set<int>> &G, set<int> &S){
    S.erase(i);
    for(auto p: G.at(i)){
        if(S.count(p)){
            dfs(p, G, S);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<set<int>> G(n);
    vector<int> A(m),B(m);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        A.at(i)=a;
        B.at(i)=b;
        G.at(a).insert(b);
        G.at(b).insert(a);
    }
    int ans=0;
    for(int i=0; i<m; i++){
        set<int> S;
        for(int i=0; i<n; i++){
            S.insert(i);
        }
        int a=A.at(i);
        int b=B.at(i);
        G.at(a).erase(b);
        G.at(b).erase(a);
        dfs(0, G, S);
        if(!S.empty()) ans++;
        G.at(a).insert(b);
        G.at(b).insert(a);
    }
    cout << ans << endl;
}