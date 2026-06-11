#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
const int INF = 1e9;
const LL LLINF = 1e16;

string dp[10101];

void chmax(string& a, string b){
    // cout << a << " " << b << endl;
    if (a.size() < b.size()) a = b;
    else if(a.size() == b.size() && a < b) a = b;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cost = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> v(m), w(m);
    rep(i, m){
        cin >> v[i];
        w[i] = cost[v[i]-1];
        // cout << v[i] << " " << w[i] << endl;
    }

    rep(i, n){
        rep(j, m){
            if(i == 0) dp[i+w[j]] = v[j]+'0';
            else if(dp[i] != ""){
                string next;
                if(dp[i][0]-'0' < v[j]){
                    next = v[j]+'0';
                    next += dp[i];
                }else{
                    next = dp[i];
                    next += v[j]+'0';
                }
                chmax(dp[i+w[j]], next);
            }
            // cout << dp[i+w[j]] << " (" << i+w[j] << ")" << endl;
        }
            // cout << endl;

    }
    cout << dp[n] << endl;

}