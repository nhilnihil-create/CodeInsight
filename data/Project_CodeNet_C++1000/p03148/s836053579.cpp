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
#define int long long
vector<int> v[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int ans = 0;
    
    rep(i, N) {
        int t, d;
        cin >> t >> d;
        t--;
        v[t].push_back(d);
    }
    rep(i, N) sort(v[i].begin(), v[i].end());
    priority_queue<int> que1, que2;
    priority_queue<int, vector<int>, greater<int>> que3;
    rep(i, N) {
        if(v[i].size()) {
            que1.push(v[i].back()); 
            v[i].pop_back();
        }
    }
    rep(i, N) for(auto& e: v[i]) que2.push(e);
    rep(i, N) for(auto& e: v[i]) que3.push(e);
    int sum1 = 0, sum2 = 0;
    rep(i, K) {
        if(que2.size()) {
            sum2 += que2.top(); que2.pop();
        }
    }
    while(que3.size() > K) que3.pop();
    //cout << que3.size() << " " << que2.size() << endl;
    rep(i, N) {
        if(que1.size() == 0) break;
        //cout << que1.top() << " " << que3.top() << " " << que3.size() + i + 1  << " ";
        sum1 += que1.top(); que1.pop();
        while(que3.size() && i + 1 + que3.size() > K) {
            sum2 -= que3.top(); que3.pop();
        }
        if(i + 1 + que3.size() > K) break;
        //cout << que3.size() + i + 1 << " " << sum1 << " " << sum2 << " " << sum1 + sum2 + (i + 1) * (i + 1) << endl;
        ans = max(ans, sum1 + sum2 + (i + 1) * (i + 1));
    }
    cout << ans << endl;
    

    return 0;
}
