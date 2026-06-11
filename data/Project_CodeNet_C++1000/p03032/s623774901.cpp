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
    int n, k;
    cin >> n >> k;
    int V[51];
    rep(i, n) cin >> V[i];
    int ans = 0;
    rep(i, n + 1) {
        rep(j, n + 1) {
            if(i + j > n || i + j > k) continue;
            int sum = 0;
            priority_queue<int, vector<int>, greater<int>> que;
            rep(t, i) {sum += V[t]; que.push(V[t]);}
            rep(t, j) {sum += V[n - 1 - t]; que.push(V[n - 1 - t]);}
            int remain = k - i - j;
            while(remain && que.size() && que.top() < 0) {
                sum -= que.top();
                que.pop();
                remain--;
            }
            //cout << i << " " << j << " " << sum << endl;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;

    return 0;
}
