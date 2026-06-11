#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    ll N, M;
    string S;
    cin >> N >> M >> S;
    ll po[N] = {};
    vector<vector<ll>> edges(N), an(N), bn(N);
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        (S[b] == 'A' ? an : bn)[a].push_back(b);
        (S[a] == 'A' ? an : bn)[b].push_back(a);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bool ng[N] = {};
    vector<ll> starts;
    for(ll i = 0; i < N; i++) if(an[i].empty() || bn[i].empty()) starts.push_back(i);
    for(auto start : starts){
        if(ng[start]) continue;
        ng[start] = 1;
        queue<ll> q;
        q.push(start);
        while(q.size()){
            ll now = q.front();
            q.pop();
            for(ll next : edges[now]){
                if(ng[next]) continue;
                ll tmp = 0;
                for(ll po : an[next]) if(!ng[po]) tmp |= 1;
                for(ll po : bn[next]) if(!ng[po]) tmp |= 2;
                if(tmp == 3) continue;
                q.push(next);
                ng[next] = 1;
            }
        }
    }
    for(ll i = 0; i < N; i++){
        if(!ng[i]){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
