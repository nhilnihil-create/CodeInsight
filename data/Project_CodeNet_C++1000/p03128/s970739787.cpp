#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int INF = 100010;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    int need[10];
    need[1]=2; need[2]=5; need[3]=5;
    need[4]=4; need[5]=5; need[6]=6;
    need[7]=3; need[8]=7; need[9]=6;
    int dp[n];
    rep(i,n+1) dp[i] = -INF;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        rep(j,m){
            if(i-need[a[j]]>=0){
                dp[i] = max(dp[i],dp[i-need[a[j]]]+1);
            }
        }
    }
    string ans = "";
    int rem=dp[n];
    int match=n;
    sort(a.begin(),a.end(),greater<int>());
    while(rem>0){
        rep(i,m){
            if(match-need[a[i]]>=0){
                if(dp[match-need[a[i]]] == rem-1){
                    string s = to_string(a[i]);
                    ans += s;
                    match -= need[a[i]];
                    rem--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

