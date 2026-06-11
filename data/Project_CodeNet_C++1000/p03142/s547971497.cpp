#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
 
const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);
 
using namespace std;
int cnt [100005];
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
    cin >> N >> M;
    vector<int> ans(N);
    vector<vector<int>> to(N),from(N);
    rep(i,N+M-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        from[b].push_back(a);
        cnt[b]++;
    }
    int parent = -1;
    rep(i,N) if(cnt[i]==0){
        parent = i;
    }
    queue<int> q;
    q.push(parent);
    ans[parent] = -1;
    int now = parent;
    while(!q.empty()){
        int now = q.front();q.pop();
        for(int i=0;i<to[now].size();i++){
            int next = to[now][i];
            if(from[next].size()==1){
                q.push(next);
                ans[next] = now;
            }else{
                for(int j=0;j<from[next].size();j++){
                    if(from[next][j]==now){
                        from[next].erase(from[next].begin()+j);
                        break;
                    }
                }
            }
        }
    }
    rep(i,N)cout << ans[i] + 1 << endl;
}