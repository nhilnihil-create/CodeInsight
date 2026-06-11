//
// Created by yamunaku on 2019/08/30.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vi a(n,0),b(n,0);
    mti e(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        e[u].push_back(v);
        e[v].push_back(u);
        if(s[u]=='A') a[v]++;
        else b[v]++;
        if(s[v]=='A') a[u]++;
        else b[u]++;
    }
    vector<int> ok(n,1);
    queue<int> q;
    int c=n;
    rep(i,n){
        if(a[i]==0||b[i]==0){
            c--;
            q.push(i);
            ok[i]=false;
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto nx:e[now]){
            if(s[now]=='A'){
                a[nx]--;
            }else{
                b[nx]--;
            }
            if(ok[nx]&&(a[nx]==0||b[nx]==0)){
                c--;
                q.push(nx);
                ok[nx]=false;
            }
        }
    }
    if(c==0) CNO;
    else CYES;
    return 0;
}
