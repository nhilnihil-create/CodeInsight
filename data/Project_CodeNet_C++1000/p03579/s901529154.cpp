#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N, M;
int A[100000], B[100000];
vector<int> E[100000];
int dist[100000];

signed main(){
    cin >> N >> M;
    rep(i, M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        E[A[i]].pb(B[i]);
        E[B[i]].pb(A[i]);
    }

    rep(i, N) dist[i] = INT_MAX;
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int n = que.front();
        que.pop();
        rep(i, E[n].size()){
            if(dist[E[n][i]] > dist[n] + 1){
                dist[E[n][i]] = dist[n] + 1;
                que.push(E[n][i]);
            }
        }
    }

    rep(i, M){
        if(dist[A[i]]%2 == dist[B[i]]%2){
            cout << (ll)N*(N-1)/2 - M << endl;
            return 0;
        }
    }
    ll cnt = 0;
    rep(i, N){
        cnt += dist[i]%2;
    }
    cout << cnt*(N-cnt) - M << endl;
}