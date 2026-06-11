#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> cost={0,2,5,5,4,5,6,3,7,6};
    vector<char> A(M);
    rep(i,M){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    vector<string> dp(N+1,"");
    rep(i,N+1){
        rep(j,M){
            if (dp[i]!=""||i==0){
                int k=i+cost[A[j]-'0'];
                if (k<=N&&dp[k]==""){
                    dp[k]=dp[i]+A[j];
                }
                else if (k<=N&&dp[k]!=""){
                    if ((dp[i]+A[j]).size()>dp[k].size()){
                        dp[k]=dp[i]+A[j];
                    }
                    else if ((dp[i]+A[j]).size()==dp[k].size())
                    dp[k]=max(dp[k],dp[i]+A[j]);
                }
            }
        }
    }
    cout << dp[N] << endl;
}