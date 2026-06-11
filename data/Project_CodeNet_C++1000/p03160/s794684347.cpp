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
    int n;
    cin >> n;
    vector<int> h(n+1);
    rep(i,n)cin >> h[i+1];
    h[0]=1000000;
    vector<int> dp(n+1);
    dp[0]=1000000;
    dp[1]=0;
    for(int i=2;i<=n;++i){
        dp[i]=min((dp[i-1]+abs(h[i]-h[i-1])),(dp[i-2]+abs(h[i]-h[i-2])));
    }
    cout << dp[n] << endl;
}