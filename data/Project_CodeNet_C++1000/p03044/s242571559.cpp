#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct Edge{
    int from, to, cost;
};


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

struct edge{
    ll to, cost;
};

int main(){
    ll n;
    cin>>n;

    vector<edge> g[n];
    for(ll i=0;i<n-1;++i){
        ll u, v, w;
        cin>>u>>v>>w;
        u--;
        v--;
        edge e1 = {u, w};
        edge e2 = {v, w};
        g[v].push_back(e1);
        g[u].push_back(e2);
    }

    vector<ll> ans(n, 0);
    ans[0] = 0;
    queue<ll> que;
    que.push(0);
    vector<ll> d(n, -1);
    d[0] = 0;
    while(!que.empty()){
        ll a = que.front();
        que.pop();
        for(auto val : g[a]){
            ll na = val.to;
            if(d[na] != -1)continue;
            d[na] = d[a] + val.cost;
            if(d[na] % 2 == 0){
                ans[na] = 0;
            }else{
                ans[na] = 1;
            }
            que.push(na);
        }
    }

    for(ll i=0;i<n;++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}