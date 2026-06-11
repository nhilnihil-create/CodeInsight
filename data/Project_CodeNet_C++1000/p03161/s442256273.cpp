#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n)cin >> h[i];
    vector<int> dp(n);
    dp[0]=0;
    for(int i=1;i<n;++i){
        int val=MAX;
        for(int j=1;j<=k;++j){
            if(i-j<0){
                break;
            }
            val=min(val,dp[i-j]+abs(h[i]-h[i-j]));
        }
        dp[i]=val;
    }
    cout << dp[n-1] << endl;
}