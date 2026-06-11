#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, M, ans=0, tmp=0;
vector<pair<ll, ll>> A;

void myfunc(ll num) {
    vector<ll> E[N];
    for(int i=0;i<M;i++) {
        if(i==num) continue;
        pair<ll, ll> p = A[i];
        E[p.first].push_back(p.second);
        E[p.second].push_back(p.first);
    }
    queue<ll> Q;
    ll color[N]={0};
    Q.push(0);
    color[0]=1;
    while(!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for(int i=0;i<E[u].size();i++) {
            if(color[E[u][i]]==1) continue;
            Q.push(E[u][i]);
            color[E[u][i]]=1;
        }
    }
    for(int i=0;i<N;i++) {
        if(color[i]==0) {
            ans++;
            return;
        }
    }
}

signed main(){
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        A.push_back(make_pair(a,b));
    }
    for(int i=0;i<M;i++) {
        myfunc(i);
    }
    cout << ans << endl;
    return 0;
}