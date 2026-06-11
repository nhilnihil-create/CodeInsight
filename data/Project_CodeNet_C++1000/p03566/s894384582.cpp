#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
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

int ans[41000];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int t[110], v[110];
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> v[i];
    int sumT = 0;
    rep(i, n) sumT += t[i] * 2;
    int k = 0;
    int T = t[0] * 2;
    int i = 0;
    while(k < n) {
        ans[i + 1] = min(ans[i] + 1, v[k] * 2);
        i++;
        T--;
        if(T == 0) {k++; T = t[k] * 2;}
    }
    k = n - 1;
    T = t[n - 1] * 2;
    ans[i] = 0;
    while(k >= 0) {
        ans[i - 1] = min({ans[i - 1], ans[i] + 1, v[k] * 2});
        i--;
        T--;
        if(T == 0) {k--; T = t[k] * 2;}
    }
    //rep(i, 220) cout << i/2.0 << " " << ans[i]/2.0 << endl;
    int sum = 0;
    rep(i, 40001) sum += ans[i];
    cout << fixed << setprecision(12) << sum/4.0 << endl;


    return 0;
}
