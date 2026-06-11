#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    int N;
    cin  >> N;
    graph G(N);
    vector<pair<ll,ll>> E(N - 1);
    for(int i = 0; i < N; i++){
        G[i] = vector<ll>(0);
    }
    for(int i = 0; i < N - 1; i++){
        ll A,B;
        cin >> A >>B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
        E[i].first = A;
        E[i].second = B;
    }
    vector<ll> c(N);
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    sort(c.begin(),c.end(),greater<ll>());
    vector<ll> V(N);
    for(int i = 0; i < N; i++){
        V[i] = -1;
    }
    queue<ll> q = queue<ll>();
    q.push(0);
    ll paintCount = 0;
    while(!q.empty()){
        ll currentV = q.front();q.pop();
        V[currentV] = c[paintCount];
        paintCount++;
        for(int i = 0; i < G[currentV].size(); i++){
            ll next = G[currentV][i];
            if(V[next] != -1){
                continue;
            }
            q.push(G[currentV][i]);
        }
    }
    ll score = 0;
    for(int i = 0; i < N -1; i++){
        score += min(V[E[i].first],V[E[i].second]);
    }
    cout << score << endl;
    for(int i = 0; i < N; i++){
        cout << V[i] << endl;
    }
}