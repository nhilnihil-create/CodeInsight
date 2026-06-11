#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using ll = long long;
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

void OutputGraph(graph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j]<< ",";
        }
        cout << endl;
    }
}

int main() {
    ll N,K;
    cin >> N >> K;
    auto a = InputVec(N);
    vector<ll> sum(N + 1);
    sum[0] = 0;
    for (int i = 1; i < N + 1; ++i) {
        sum[i] += sum[i - 1] + a[i - 1];
    }
    //sum[i] = i-1までの総和
    ll res = 0;
    for (int i = 40; i >= 0; --i) {
        ll count = 0;
        //cout << (res + (1ll << i)) << endl;
        for (int j = 0; j < N; ++j) {
            //cout << ((res + (1ll << i)) & a[j]) << endl;

        }
        for (int si = 0; si < N; ++si) {
            for (int gi = si + 1; gi < N + 1; ++gi) {
                ll b = sum[gi] - sum[si];
                if(((res + (1ll << i)) & b) == (res + (1ll << i))){
                    count++;
                }
            }
        }
        if(count >= K){
            res += 1ll << i;
        }
    }
    cout << res << endl;
}
