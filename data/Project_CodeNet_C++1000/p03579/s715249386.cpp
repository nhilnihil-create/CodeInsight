#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;
bool dfs(vector<vll> &G, vll &color, ll v, ll c){
    color[v] = c;
    for(ll i=0; i< G[v].size(); i++){
        if(color[G[v][i]] == c) return false;
        if(color[G[v][i]] == 0 && dfs(G, color, G[v][i], -c)==false) return false;
    }
    return true;
}
void solve(long long N, long long M, std::vector<long long> A, std::vector<long long> B){
    vector<vll> G(N);
    for(ll i=0; i< M; i++){
        G[A[i]-1].push_back(B[i]-1);
        G[B[i]-1].push_back(A[i]-1);
    }
    vll color(N, 0);
    bool isGood;
    isGood = dfs(G, color, 0, 1);
    if(!isGood) {
        cout << N*(N-1)/2 - M << endl;
    }
    else{
        ll cnt=0;
        for(ll i=0; i< N; i++){
            if(color[i] == 1) cnt++;
        }
        cout << (cnt * (N - cnt) - M) << endl;
    }

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, M, std::move(A), std::move(B));
    return 0;
}
