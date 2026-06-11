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

int sum[100010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string S; cin >> S;
    rep(i, n) {
        if(S[i] == 'A' && S[i + 1] == 'C') sum[i + 1]++;
    }
    rep(i, n) sum[i + 1] += sum[i];
    // rep(i, n + 1) cout << sum[i];
    // cout << endl;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << sum[r] - sum[l] << endl;
    }


    return 0;
}
