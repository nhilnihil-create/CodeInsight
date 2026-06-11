#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<bool> seen(N,false);
    vector<vector<int>> edge(N,vector<int>());
    vector<int> C(N);
    vector<int> D(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ll M=0;
    rep(i,N){
        cin >> C[i];
        M += C[i];
    }
    sort(C.rbegin(),C.rend());
    cout << M - C[0] << endl;
    queue<int> q;
    q.push(0);
    seen[0]=true;
    int ix = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        D[now] = C[ix];
        ix++;
        for(auto nx:edge[now]){
            if(seen[nx]==false){
                q.push(nx);
                seen[nx]=true;
            }
        }
    }
    rep(i,N){
        cout << D[i] << " ";
    }
    cout << endl;
    return 0;
}