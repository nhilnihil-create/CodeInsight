#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int N;
vector<int> graph[10010];
vector<int> C,ans;
int idx = 0;
void dfs(int from, int now){
    //cout << from << " " << now << " " << idx << endl;
    ans[now] = C[idx];
    for(auto next: graph[now]){
        if(next == from)continue;
        idx++;
        dfs(now, next);
    }
}
main(){
    cin >> N;
    vector<int> A(N-1), B(N-1);
    rep(i,0,N-1){
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }
    C.resize(N);
    ans.resize(N);
    rep(i,0,N)cin >> C[i];
    sort(C.rbegin(), C.rend());
    
    dfs(-1, 0);

    ll sum = 0;
    rep(i,0,N-1){
        sum += min(ans[A[i]], ans[B[i]]);
    }
    cout << sum << endl;
    rep(i,0,N){
        cout << ans[i] << " \n"[i==N-1];
    }

}