#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const int INF=1000000000;




int main(){
    int N;cin >> N;
    vector<int> t(N),v(N);
    LL T=0;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        T+=t[i];
        t[i]*=2;
    }
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        v[i]*=2;
    }
    v.pb(0);
    t.pb(2);
    vector<vector<double>> dp(2*T+1,vector<double> (201,0.0));
    int c=0;
    for (int i = 0; i < 2*T; i++) {
        int lim=v[c];
        if(--t[c]==0){
            c++;
            lim=min(v[c],lim);
        }
        for (int j = 0; j < 201; j++) {
            if(dp[i][j]==0.0&&j!=0) continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+j/4.);
            if(j<200) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+j/4.+0.025);
            if(j>0) dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+j/4.-0.025);
        }
        for (int j = lim+1; j < 201; j++) {
            dp[i+1][j]=0.0;

        }
    }
    cout << setprecision(10) << fixed << dp[2*T][0] << endl;
    return 0;
}

