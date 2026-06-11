#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int n; cin >> n;
    char s[n][n];
    rep(i,n)rep(j,n) cin >> s[i][j];
    
    int ans=0;
    rep(t,2*n-1){
        bool flg=0;
        rep(i,n){
            rep(j,n){
                int x=(j+t)%n;
                int y=(i-t+1000*n)%n;

                if(s[i][j] != s[x][y]){
                    flg=1; break;
                }
            }
            if(flg) break;
        }
        if(flg) continue;
        if(t>=n) ans+=(2*n-t-1);
        else ans+=(t+1);
    }
    cout << ans << endl;
}
