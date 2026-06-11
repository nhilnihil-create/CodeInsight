#include <bits/stdc++.h>
#define INF 1e9
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<int> B(M), C(M);
    vector<pii> command(M);
    for (int i = 0; i < M; i++)
    {
        cin >> B[i] >> C[i];
        command[i] = {C[i], B[i]};
    }
    
    sort(A.begin(), A.end());
    sort(command.begin(), command.end(), greater<pii>());
    int start = 0;
    for (int i = 0; i < M; i++)
    {
        int lb = lower_bound(A.begin() + start, A.end(), command[i].first) - (A.begin() + start);
        
        fill(A.begin() + start, A.begin() + start + min(lb, command[i].second), command[i].first);
        start += min(lb, command[i].second);
    }

    ll ans = 0;    

    for (int i = 0; i < N; i++)
    {
        ans += (ll) A[i];
    }
    
    cout << ans << endl;

    return 0;
}
