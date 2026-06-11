#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

int cnt[200001];
int main()
{
    cin >> N >> K;
    memset(cnt, 0, N+1);
    int ans = 0;
    rep(i, N){
        cin >> A;
        cnt[A]++;
    }
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i, N+1){
        if(cnt[i] != 0) que.push(cnt[i]);
    }
    while(que.size() > K){
        ans += que.top();
        que.pop();
    }
    cout << ans;
}
