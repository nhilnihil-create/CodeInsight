#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
//const ll MOD=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI = 2.0*acos(0);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void solve(int ca){
    int N,M; cin>>N>>M;
    vector<int> to[100010];
    int cnt[100010]={0};
    int ans[100010]={0};
    for (int i = 0; i < N + M - 1; ++i) {
        int a,b; cin>>a>>b;
        to[a].push_back(b);
        to[b].push_back(a);
        cnt[b]++;
    }
    int root=0;
    for (int i = 1; i <= N; ++i) {
        if(cnt[i]==0) {
            root=i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int node =q.front();
        q.pop();
        //cout<<node<<endl;
        for(auto i:to[node]){
            --cnt[i];
            if(cnt[i]!=0){
                continue;
            }
            ans[i]=node;
            q.push(i);
        }
    }
    for(int i=1;i<=N;++i){
        cout<<ans[i]<<endl;
    }

}

//#define MULTI
int main() {
#ifdef MULTI
    int N; cin>>N;
    for (int i = 0; i < N; ++i) {
        solve(i+1);
    }
#else
    solve(0);
#endif
    return 0;
}
