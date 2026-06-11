#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> G;

int main(){
    int n;
    cin>>n;
    G.resize(n);

    int a[n-1],b[n-1];
    rep(i,n-1){
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    vector<int> c(n);
    rep(i,n) cin>>c[i];
    sort(all(c));
    reverse(all(c));
    ll ans=0;
    for(int i=1;i<n;i++) ans+=c[i];

    queue<int> que;
    vector<int> d(n,-1);
    ll seek=0;
    que.push(0);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        d[v]=c[seek];
        seek++;
        for(int nv : G[v]){
            if(d[nv]!=-1) continue;
            que.push(nv);
        }
    }

    cout<<ans<<endl;
    rep(i,n) cout<<d[i]<<" ";
    cout<<endl;
}


 