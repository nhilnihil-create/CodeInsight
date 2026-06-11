#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> ans;
    if (A + B > N + 1) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, N - A + 1, N) ans.push_back(i);
    int remain = N - A;
    B--;
    while(B > 0) {
        //dump(remain);
        int len = remain / B;
        if (len > A) {
            cout << -1 << endl;
            return 0;
        }
        REP(i, remain - len + 1, remain) ans.push_back(i);
        B--;
        remain -= len;
    }
    if (ans.size() != N) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, N) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }


    return 0;
}
