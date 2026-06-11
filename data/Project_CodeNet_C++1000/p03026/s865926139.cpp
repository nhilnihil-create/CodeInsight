#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

int sum = 0;
bool used[10010] = {};
vector<int> V[10010];
vector<int> ans(10010);
int k = 0;
vector<int> C;
void DFS(int X){
    used[X] = 1;
    REP(i,V[X].size()){
        if(used[V[X][i]]) continue;
        ans[V[X][i]] = C[k];k++;
        DFS(V[X][i]);
    }
}

void dfs(int X){
    used[X] = 1;
    REP(i,V[X].size()){
        if(used[V[X][i]]) continue;
        sum += min(ans[V[X][i]],ans[X]);
        dfs(V[X][i]);
    }
}

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N;cin >> N;
    int A[N],B[N];
    REP(i,N-1){
        cin >> A[i] >> B[i];--A[i];--B[i];
        V[A[i]].pb(B[i]);
        V[B[i]].pb(A[i]);
    }int tmp;
    REP(i,N){cin >> tmp;C.pb(tmp);}
    sort ALL(C);reverse ALL(C);
    int maxv = 0,val;
    REP(i,N){
        if(V[i].size() > maxv){
            maxv = V[i].size();
            val = i;
        }
    }ans[val] = C[k];k++;
    DFS(val);
    REP(i,N) used[i] = 0;
    dfs(0);
    cout << sum << endl;
    REP(i,N){
        cout << ans[i] << ' ';
    }
    cout << endl;
}