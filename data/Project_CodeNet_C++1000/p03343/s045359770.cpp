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
    int N, K, Q;
    cin >> N >> K >> Q;
    int A[2010];
    rep(i, N) cin >> A[i];
    int ans = INF;
    rep(i, N) {
        vector<priority_queue<int, vector<int>, greater<int>>> v;
        priority_queue<int, vector<int>, greater<int>> que;
        rep(j, N) {
            if(A[j] >= A[i]) que.push(A[j]);
            else if(que.size()) {
                v.push_back(que);
                while(que.size()) que.pop();
            }
        }
        if(que.size()) v.push_back(que);
        vector<int> v2;
        for(auto& e: v) {
            //cout << i << " " << e.size() << endl;
            while(e.size() >= K) {
                int p = e.top(); e.pop();
                v2.push_back(p);
            }
        }
        if(v2.size() >= Q) {
            sort(v2.begin(), v2.end());
            ans = min(ans, v2[Q - 1] - A[i]);
        }
    }
    cout << ans  << endl;


    return 0;
}
