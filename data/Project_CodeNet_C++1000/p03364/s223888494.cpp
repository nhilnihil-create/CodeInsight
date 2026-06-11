#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
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
    int N; cin >> N;
    string S[310];
    rep(i, N) cin >> S[i];
    int ans = 0;
    rep(A, N) {
        bool ok = true;
        rep(i, N) {
            rep(j, N) {
                int i1 = (i + A) % N;
                int j1 = j;
                int i2 = (j + A) % N;
                int j2 = i;
                if(S[i1][j1] != S[i2][j2]) ok = false;
                //cout << i1 << " " << j1 << " " << S[i1][j1] << " " << i2 << " " << j2 << " " << S[i2][j2] << endl;
            }
        }
        ans += ok;
    }
    cout << ans * N << endl;

    return 0;
}
