#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    REP(i,n)cin >> a[i];

    const int MAX_DIGIT = 50;
    ll dp[MAX_DIGIT+1][2];
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;

    REP(i,MAX_DIGIT){
        ll mask = (ll)1 << (MAX_DIGIT-1-i);
        ll num = 0;
        REP(j,n)if(a[j]&mask)num++;
        ll cost0 = num*mask;
        ll cost1 = (n-num)*mask;

        if(dp[i][1]!=-1){
            chmax(dp[i+1][1],dp[i][1]+max(cost0,cost1));
        }
        if(dp[i][0]!=-1){
            if(mask&k)chmax(dp[i+1][1],dp[i][0]+cost0);
        }
        if(dp[i][0]!=-1){
            if(mask&k)chmax(dp[i+1][0],dp[i][0]+cost1);
            else chmax(dp[i+1][0],dp[i][0]+cost0);
        }
    }
    cout << max(dp[MAX_DIGIT][0],dp[MAX_DIGIT][1]) << endl;
    return 0;
}