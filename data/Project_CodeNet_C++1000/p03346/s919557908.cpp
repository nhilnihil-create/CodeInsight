#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    // dp[i]:iを最後とする最長部分列の長さ
    vector<int> dp(N+1);
    rep(i,N){
        int p;
        cin >> p;
        dp[p] = dp[p-1]+1; // 1つ前までの長さから1伸びるか、新たに1となるか
    }
    sort(dp.rbegin(),dp.rend());
    cout << N - dp[0] << endl;
    return 0;
}