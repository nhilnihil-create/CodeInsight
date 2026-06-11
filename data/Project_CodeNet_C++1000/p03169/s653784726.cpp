#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int n;
vector<int>a(n);

double dp[310][310][310];
double rec(int i,int j,int k){
    if(dp[i][j][k]>=0)return dp[i][j][k];//DPテーブルの値が既に決まっていたらそれを返す
    if(i==0&&j==0&&k==0)return 0.0;
    double res = 0.0;
    if(i>0) res += rec(i-1,j,k) * i;
    if(j>0) res += rec(i+1,j-1,k) * j;
    if(k>0) res += rec(i,j+1,k-1) * k;
    res += n;
    res *= 1.0/(i+j+k);
    dp[i][j][k] = res;
    return res;
}


int main(){
    cin >> n;
    a.resize(n);
    rep(i,n)cin>>a[i];
    int one = 0,two = 0,three = 0;
    rep(i,n){
        if(a[i]==1)one++;
        if(a[i]==2)two++;
        if(a[i]==3)three++;
    }
    rep(i,310)rep(j,310)rep(k,310)dp[i][j][k]=-1;
    double ans = rec(one,two,three);
    cout << printf("%.16lf",ans) << endl;

    return 0;
}
