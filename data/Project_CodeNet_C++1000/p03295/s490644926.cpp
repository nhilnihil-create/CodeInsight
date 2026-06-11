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

typedef pair<int, int> P;
vector<int> v[100010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[b].push_back(a);
    }
    rep(i, N) sort(v[i].begin(), v[i].end());
    int ans = 0;
    int last = -1;
    rep(i, N) {
        if(v[i].size() == 0) continue;
        if(last < v[i].back()) {
            ans++;
            last = i - 1;
        }
    }
    cout << ans << endl;



    return 0;
}
