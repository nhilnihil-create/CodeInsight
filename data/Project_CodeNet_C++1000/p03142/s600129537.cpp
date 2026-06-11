#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
using ll = long long;
using uint = unsigned int;
using graph = std::vector<std::vector<ll>>;
using wGraph = std::vector<std::vector<std::pair<ll,ll>>>;
#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;
ll MOD7 = 1000000007;
ll MOD9 = 1000000009;
vector<ll> InputVec(ll N){
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    return A;
}
void OutputVec(vector<ll> A){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;
}
vector<vector<ll>> InputVec2d(ll H,ll W){
    vector<vector<ll>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            cin >> A[yi][xi];
        }
    }
    return A;
}
vector<vector<char>> InputVec2dStr(ll H,ll W){
    vector<vector<char>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<char>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        string S;
        cin >> S;
        for (int xi = 0; xi < W; ++xi) {
            A[yi][xi] = S[xi];
        }
    }
    return A;
}
void OutputVec2d(vector<vector<ll>> A){
    for (int yi = 0; yi < A.size(); ++yi) {
        for (int xi = 0; xi < A[yi].size(); ++xi) {
            cout << A[yi][xi] << ",";
        }
        cout << endl;
    }
}
graph InputGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return G;
}
graph InputDGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
    }
    return G;
}
wGraph InputWGraph(ll N,ll M){
    wGraph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    return G;
}
wGraph InputDWGraph(ll N, ll M){
    wGraph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back(make_pair(b,c));
    }
    return G;
}
void OutputGraph(graph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j]<< ",";
        }
        cout << endl;
    }
}

void OutputGraph(wGraph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j].first <<"/" << G[i][j].second << ",";
        }
        cout << endl;
    }
}

void OutputAnswerBool(bool b,bool isUpperCase = false){
    if(b){
        if(isUpperCase){
            cout << "YES" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }else{
        if(isUpperCase){
            cout << "NO" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

void solveTS(ll i,graph &G,ll N,vector<bool> &seen,vector<ll> &res){
    seen[i] = true;
    for (int j = 0; j < G[i].size(); ++j) {
        ll next = G[i][j];
        if(seen[next]){
            continue;
        }
        solveTS(next,G,N,seen,res);
    }
    res.push_back(i);
}

vector<ll> topologicalSort(graph &G, ll N){
    vector<ll> res;
    vector<bool> seen(N);
    for (int i = 0; i < N; ++i) {
        if(!seen[i]){
            solveTS(i,G,N,seen,res);
        }
    }
    reverse(res.begin(),res.end());
    return res;

}

int main() {
    ll N,M;
    cin >> N >> M;
    graph G = InputDGraph(N,N-1+M);
    //OutputGraph(G);
    auto sorted = topologicalSort(G,N);
    //OutputVec(sorted);
    vector<ll> parent(N,-1);
    for (int i = 0; i < N; ++i) {
        ll current = sorted[i];
        for (int j = 0; j < G[current].size(); ++j) {
            parent[G[current][j]] = current;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << parent[i] + 1 << endl;
    }
}
