#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;

//トポロジカルソート 隣接リスト　頂点の入次数 頂点数 O(N+M)
vll topological_sort(vvll next, vll &indegree, ll N) {
    vll sorted_vertices;

    queue<ll> que;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    while (que.empty() == false) {
        ll v = que.front();
        que.pop();

        for (ll i = 0; i < next[v].size(); i++) {
            ll u = next[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        sorted_vertices.push_back(v);
    }

    return sorted_vertices;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,M;
    cin>>N>>M;
    vll A(N-1+M),B(N-1+M);
    vvll next(N);
    vll indegree(N,0);
    for(ll i=0;i<N-1+M;i++){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        next[A[i]].push_back(B[i]);
        indegree[B[i]]++;
    }
    
    vll sorted=topological_sort(next, indegree, N);
    
    vll ans(N,0);
    
    for(ll i=0;i<N;i++){
        for(ll j=0;j<next[sorted[i]].size();j++){
            ans[next[sorted[i]][j]]=sorted[i]+1;
        }
    }
    for(ll i=0;i<N;i++){
        printf("%lld\n",ans[i]);
    }
    
    return 0;
}
