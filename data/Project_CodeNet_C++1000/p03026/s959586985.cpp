#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;



int main(){
    ll N; cin >> N;
    vector<vector<ll>> V(N);
    for(int i = 0; i < N-1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    vector<ll> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    sort(C.rbegin(), C.rend());
    vector<bool> Grid(N);
    set<pair<ll, ll>> ST;
    ll score = 0;
    for(int i = 1; i < N; i++) score += C[i];
    queue<ll> Q; Q.push(0); Grid[0] = true;
    int idx = 1; ST.insert(make_pair(1, C[0]));
    while(!Q.empty()){
        ll x = Q.front(); Q.pop();
        for(auto v : V[x]){
            if(!Grid[v]){
                Grid[v] = true;
                ST.insert(make_pair(v+1, C[idx]));
                idx++;
                Q.push(v);
            }
        }
    }
    
    cout << score << endl;
    for(auto s : ST){
        cout << s.second << " ";
    }
    cout << endl;


}
