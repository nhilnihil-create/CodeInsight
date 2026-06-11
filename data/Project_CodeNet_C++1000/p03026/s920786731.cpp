#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    vector<vector<ll> > G(n+1);
    for(i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> c(n);
    for(i=0;i<n;i++){
        cin >> c[i];
    }
    sort(c.begin(),c.end());
    vector<ll> deg(n+1,0);
    queue<ll> pq;
    for(i=1;i<=n;i++){
        deg[i]=(ll)G[i].size();
        if(deg[i]==1){
            pq.push(i);
        }
    }

    ll ret[n+1]={},cnt=0,sum=0;
    while(!pq.empty()){
        ll x = pq.front();
        pq.pop();
        ret[x] = c[cnt++];
        //cout << x << endl;
        for(ll y:G[x]){
            if(ret[y]==0){
                sum+=ret[x];
                deg[y]--;
                if(deg[y]==1){
                    pq.push(y);
                }
            }
        }
    }
    cout << sum << endl;
    for(i=1;i<=n;i++){
        cout << ret[i] << " ";
    }
    cout << endl;
        
    return 0;
}