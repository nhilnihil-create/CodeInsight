//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

vector<bool> seen;

void dfs(vecveci &G, int v) {
    seen[v] = true;
    for(int w : G[v]) {
        if(seen[w]) continue; 
        dfs(G,w);
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<P> res(M);
    int ans = 0;

    REP(i,M) {
        int a,b; cin >> a >> b;
        a--;b--;
        res[i] = P(a,b);
    }

    REP(i,M) {
        vecveci G(N);
        REP(j,M) {
            if(i != j) {
                int a = res[j].first;
                int b = res[j].second;
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        /*
        cout << endl;
        REP(i,N) {
            cout << "{";
            for(int v:G[i]) cout << v << " ";
            cout << "}" << endl;
        }
        cout << endl;
        */
        seen.assign(N,false);
        int cnt = 0;
        REP(v,N) {
            if(seen[v]) continue;
            dfs(G,v);
            cnt++;
        }
        if(cnt > 1) ans++; 
    }
    cout << ans << endl;
}