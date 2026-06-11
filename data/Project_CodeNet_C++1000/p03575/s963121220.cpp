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

const int MOD = 1000000007;

int main() {
    int N,M;
    cin >> N >> M;
    int ans = 0;
    vector<P> edge(M);
    REP(i,M) cin >> edge[i].first >> edge[i].second;
    REP(i,M) {
        vecveci G(N);
        REP(j,M) {
            if(i != j) {
                int a = edge[j].first;
                int b = edge[j].second;
                a--;
                b--;
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }

            vector<int> dist(N,-1);
            queue<int> que;
            int count = 0;
            for(int v = 0; v < N; v++) {
                if(dist.at(v) != -1) continue;
                dist.at(v) = 0;
                que.push(v);
                while(!que.empty()) {
                    int v = que.front(); 
                    que.pop();
                    for(auto w:G.at(v)) {
                        if(dist.at(w) != -1) continue;
                        que.push(w);
                        dist.at(w) = dist.at(v) + 1;
                    }
                }
                count++;
            }
            if(count > 1) ans++;
    }
    cout << ans << endl;
}
