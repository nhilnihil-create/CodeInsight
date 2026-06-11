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
#define int long long 
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, H; cin >> N >> H;
    int maxA = 0;
    vector<int> B;
    int b[100010];
    rep(i, N) {
        int a;
        cin >> a >> b[i];
        maxA = max(maxA,a);
    }
    rep(i, N) {
        if (maxA < b[i]) B.push_back(b[i]);
    }
    sort(B.begin(), B.end(), greater<int>());
    int cnt = 0;
    rep(i, B.size()) {
        H -= B[i];
        cnt++;
        if(H <= 0) {
            cout << cnt << endl;
            return 0;
        }
    }
    cout << cnt + (H + maxA - 1)/maxA << endl;


    return 0;
}
