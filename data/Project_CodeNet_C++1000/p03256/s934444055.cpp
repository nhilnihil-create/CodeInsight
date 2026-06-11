#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin >> n >> m;
    string s;cin >> s;
    vector<vector<int>> e(n);
    vector<int> a(n),b(n);
    REP(i,m){
        int u,v;cin >> u >> v;
        u--,v--;
        e[u].push_back(v);
        e[v].push_back(u);
        if(s[v]=='A') a[u]++;
        else b[u]++;
        if(s[u]=='A') a[v]++;
        else b[v]++;
    }
    vector<bool> c(n,true);
    queue<int> q;
    REP(i,n){
        if(!a[i]||!b[i]){
            q.push(i);
            c[i]=false;
        }
    }
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int x:e[p]){
            if(!c[x]) continue;
            if(s[p]=='A') a[x]--;
            else b[x]--;
            if(!a[x]||!b[x]){
                c[x]=false;
                q.push(x);
            }
        }
    }
    REP(i,n){
        if(c[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}