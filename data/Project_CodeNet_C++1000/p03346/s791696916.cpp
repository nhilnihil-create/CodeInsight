#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    int N;
    cin >> N;
    int P[N];
    rep(i, N){
        cin >> P[i];
    }

    vector<int> dp(N+1, 0);
    int ans = 0;
    rep(i, N){
        int p = P[i];
        dp[p] = dp[p-1] + 1;
        chmax(ans, dp[p]);
    }

    cout << N - ans << endl;
}
