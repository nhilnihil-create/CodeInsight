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
int N; 
int p[200010];
int _p[200010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    
    rep(i, N) cin >> p[i];
    rep(i, N) p[i]--;
    rep(i, N) _p[p[i]] = i;
    int ans = 1;
    int len = 1;
    rep(i, N - 1) {
        if(_p[i] < _p[i + 1]) len++;
        else len = 1;
        ans = max(ans, len);
        //cout << "*" << len << " " << _p[i] << " " << _p[i + 1] << endl;
    }
    cout << N - ans << endl;
    

    return 0;
}
// 8 4 5 6 7 1 2 3