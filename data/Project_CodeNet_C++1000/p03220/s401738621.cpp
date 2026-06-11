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
    int T, A;
    cin >> T >> A;
    int H[1010];
    rep(i, N) cin >> H[i];
    int num = 0;
    rep(i, N) {
        int a1 = abs(A * 1000 - (T * 1000 - H[i] * 6));
        int a2 = abs(A * 1000 - (T * 1000 - H[num] * 6));
        if(a1 < a2) {
            num = i;
        }
    }
    cout << num + 1 << endl;

    return 0;
}
