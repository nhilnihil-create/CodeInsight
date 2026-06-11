#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e12)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n; cin >> n;
    arr<int> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    vector<int> dp(1<<n, 0);
    dp[0] = 1;
    FOR(S, 1, 1<<n){
        int i = bitset<32>(S).count();
        rep(j, n){
            // もし女jがすでにマッチしており、今また男i-1とマッチできるならば
            // それはSからjがマッチしていない場合の数を、dp[S]に足すことができる。
            if(a[i-1][j]==1 && (S>>j)&1){
                dp[S] = (dp[S]+dp[S^(1<<j)])%MOD;
            }
        }
    }

    pr(dp[(1<<n)-1]);
    return 0;}