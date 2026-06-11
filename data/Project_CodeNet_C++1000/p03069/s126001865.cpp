#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
using namespace std;

#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;

const int d5 = 200100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin>>n>>s;
    int dp[d5];
    fill(dp,dp+d5,0);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='#'){
            cnt++;
        }
        dp[i]=cnt;
    }
    int dw[d5];
    fill(dw,dw+d5,0);
    cnt=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='.'){
            cnt++;
        }
        dw[i]=cnt;
    }
    /* for(int i=0;i<10;i++){
        cout<<dp[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<dw[i]<<' ';
    }
    cout<<endl; */
    int res=min(cnt,n-cnt);
    for(int i=1;i<n;i++){
        res=min(res,dp[i-1]+dw[i]);
    }
    cout<<res<<endl;
}