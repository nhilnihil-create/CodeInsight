//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const in inf=1e9+7;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};

in ketasum(in n) {
    in res = 0;
    while(n > 0) {
        res += 1;//res ++にすると桁数
        n /= 2;//10を変えるとn進数(上のも)
    }
    return res;
}

template <typename T>
bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false;}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n,k;
    cin>>n>>k;
    vector<bitset<48>> a(n);
    bitset<48> kk(k);
    in x;
        rep(i,n){
            cin>>x;
            a[i]=bitset<48>(x);
        }
    vector<in> cnt(48,0);
    rep(i,48)rep(j,n){
        if(a[j].test(i)) cnt[i] ++;
    }
    reverse(all(cnt));

    vector<vector<vector<in>>> dp(48,vector<vector<in>>(2,vector<in>(2,-1)));
    dp[0][0][0]=0;
    rep(i,47)rep(j,2)rep(h,2){
        if(dp[i][j][h]==-1) continue;
        chmax(dp[i+1][0][h||(kk.test(48-i-2))],dp[i][j][h]*2+cnt[i+1]);
        if(h==1) chmax(dp[i+1][1][1],dp[i][j][h]*2+n-cnt[i+1]);
        else if(kk.test(46-i)) chmax(dp[i+1][1][0],dp[i][j][h]*2+n-cnt[i+1]);
    }
    in ans=0;
    rep(i,2)rep(j,2){
        chmax(ans,dp[47][i][j]);
    }
    cout<<ans<<endl;
}