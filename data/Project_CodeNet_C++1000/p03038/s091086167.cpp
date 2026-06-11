#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), C(M); for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i] >> C[i];
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < N; ++i) pq.push(make_pair(A[i], 1));
    for(int i = 0; i < M; ++i) pq.push(make_pair(C[i], B[i]));

    ll ans = 0;
    while(N != 0){
        pair<int, int> top = pq.top();
        pq.pop();
        ans += (ll) top.first*min(top.second, N);
        N -= min(top.second, N);
    }
    cout << ans << '\n';
    return 0;
}
//Saw the editorial