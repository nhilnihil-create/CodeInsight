#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

vector<int> dp(100001,1000000);
void solve(){
    dp[0] = 0;
    dp[1] = 1;
    int tmp;
    for(int i=2; i<100001; i++){
        tmp = 1;
        for(int j=0; j<6; j++){
            if(tmp <= i)    dp[i] = min(dp[i], dp[i-tmp]+1);
            tmp *= 9;
        }
        tmp = 1;
        for(int j=0; j<9; j++){
            tmp *= 6;
            if(tmp <= i)    dp[i] = min(dp[i], dp[i-tmp]+1);
        }
    }
}

int main(){
    int N;  cin >> N;
    solve();
    cout << dp[N] << endl;
    return 0;
}