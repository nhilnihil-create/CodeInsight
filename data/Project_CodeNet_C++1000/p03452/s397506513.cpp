#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_code(drken)
typedef pair<int, int>pint;
typedef pair<int, int>Edge;

template<class T>inline bool chmin(T& a,T b){if(a > b){a = b;return 1;} return 0;}

const int Max = 200007;
vector<Edge> G[Max];

int l[Max],r[Max],d[Max],dp[Max];
bool isOK[Max];

int n,m;

string solve(){
    rep(i,n)dp[i]=1e+9;
    rep(i,n){
        if(isOK[i])continue;
        dp[i]=0;
        priority_queue<pint, vector<pint>,greater<pint>>que;
        que.push(pint(0,i));
        while(!que.empty()){
            pint p = que.top();
            que.pop();
            for(auto e:G[p.second]){
                if(chmin(dp[e.first],dp[p.second]+e.second)){
                    que.push(pint(dp[e.second],e.first));
                }
            }
        }
    }
    rep(i,m) if(dp[r[i]] - dp[l[i]] != d[i])return "No";
    return "Yes";
}

int main() {
    cin>>n>>m;
    rep(i,Max)G[i].clear();
    memset(isOK,0,sizeof(isOK));
    rep(i,m){
        cin>>l[i]>>r[i]>>d[i];
        --l[i];--r[i];
        G[l[i]].push_back(Edge(r[i],d[i]));
        isOK[r[i]]=true;
    }
    cout<<solve()<<endl;
	return 0;
}