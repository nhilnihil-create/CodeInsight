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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    sort(ALL(A));
    int ans = 0;
    do {
        if (M < A[ans]) break;
        M -= A[ans];
        ans++;
    } while(ans < N-1);
    if (M == A[N-1]) ans++;

    cout << ans << '\n';

    return 0;
}