#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int N; cin >> N;
    vector<ll> A(N), B(N);
    priority_queue<ll> pq;
    int ans = 0;
    REP(i,N) cin >> A[i];
    REP(i,N) {
        cin >> B[i];
        if (A[i] < B[i]) ans++;
        else pq.push(A[i]-B[i]);
    }

    ll a = 0;
    REP(i,N) {
        if (A[i] >= B[i]) continue;
        while(A[i] + a < B[i]) {
            if (pq.empty()) {
                OUT(-1)
                return 0;
            }
            a += pq.top(); pq.pop();
            ans++;
        }
        a = A[i] + a - B[i];
    }

    cout << ans << '\n';

    return 0;
}