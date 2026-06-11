#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFF 9223372036854775807
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,m,n) for(int i=m;i<n;i++)
#define ALL(N) (N.begin(),N.end())
#define de cout << "debug" << endl;
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[210000] = {};

int main() {
    cin.tie(0);    
	ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> c(200010),c2;
    REP(i,N){
        cin >> c[i];
        if(i >= 1){
            if(c[i] != c[i-1]){
                c2.pb(c[i]);
            }
        }
        else c2.pb(c[i]);
    }
    dp[0] = 1;
    vector<int> used(200010,-1);
    used[c2[0]] = 0;
    REPP(i,1,c2.size()){
        if(used[c2[i]] == -1){
            dp[i] = dp[i-1];
        }
        else {
            dp[i] = (dp[i-1] + dp[used[c2[i]]]) % 1000000007;
        }
      used[c2[i]] = i;
    }
    cout << dp[c2.size()-1] << endl;
}