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
    int C[510], S[510], F[510];
    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];
    rep(i, N) {
        int t = 0;
        for(int j = i; j < N - 1; j++) {
            t = max(t, S[j]);
            t += (F[j] - t % F[j]) % F[j] + C[j];
        }
        cout << t << endl;
    }

    return 0;
}
