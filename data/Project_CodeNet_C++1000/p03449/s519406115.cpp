#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll N;
    ll A[2][101], dp[2][101];
    cin>>N;
    rep(i, 2) rep(j, N) cin>>A[i][j];
    dp[0][0]=A[0][0];
    rep1(i, N-1) dp[0][i]=dp[0][i-1]+A[0][i];
    dp[1][0]=dp[0][0]+A[1][0];
    rep1(i, N-1) dp[1][i]=max(dp[1][i-1], dp[0][i])+A[1][i];
    cout<<dp[1][N-1]<<endl;
    return 0;
}
