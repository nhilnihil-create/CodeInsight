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
    string S[10010];
    rep(i, N) cin >> S[i];
    int ans = 0;
    int backA = 0, frontB = 0;
    int backAfrontB = 0;
    rep(i, N) {
        rep(j, S[i].length() - 1) {
            if(S[i][j] == 'A' && S[i][j + 1] == 'B') ans++;
        }
        if(S[i].back() == 'A') backA++;
        if(S[i].front() == 'B') frontB++;
        if(S[i].back() == 'A' && S[i].front() == 'B') backAfrontB++;
    }
    if(backA == frontB && backA == backAfrontB && backA > 0) ans--;
    cout << ans + min(backA, frontB) << endl;

    return 0;
}
