#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX = 110000;
int dp[MAX];

int main(){
    int n; cin >> n;
    for(int i = 0; i < MAX; ++i) dp[i] = n;
    dp[0] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0,0));//(dist, pos)
    while(!q.empty()){
        int cur = q.top().first;
        int v = q.top().second;
        q.pop();
        if(cur > dp[v]) continue;
        for(int pow6 = 1; v + pow6 <= n; pow6 *= 6){
            int nv = v + pow6;
            if(chmin(dp[nv], dp[v]+1)) q.push(make_pair(dp[nv], nv));
        }
        for(int pow9 = 1; v + pow9 <= n; pow9 *= 9){
            int nv = v + pow9;
            if(chmin(dp[nv], dp[v]+1)) q.push(make_pair(dp[nv], nv));
        }
    } 
    cout << dp[n] << endl;
}