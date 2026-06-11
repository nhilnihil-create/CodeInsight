#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main() {
    lli h,w,c,a,sum=0;
    vector<vector<lli>> dp(10,vector<lli>(10,0));
    lli i,j,k;
    cin>>h>>w;
    rep(i,0,10){
        rep(j,0,10){
            cin>>c;
            dp[i][j]=c;
        }
    }
    rep(i,0,10){
        rep(j,0,10){
            rep(k,0,10){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    rep(i,0,h){
        rep(j,0,w){
            cin>>a;
            if(a!=-1){
                sum+=dp[a][1];
            }
        }
    }
    cout<<sum<<endl;
}
