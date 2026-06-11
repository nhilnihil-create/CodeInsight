#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

int C[200000];
long long dp[200000];
long long MOD = 1000000007;
int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> C[i];
    }

    map <int, int> last;
    dp[0] = 1;
    last[C[0]] = 0;
    for(int i = 1; i < N; i++){
        if(last.find(C[i]) == last.end()){
            dp[i] = dp[i - 1];
            last[C[i]] = i;
        } else {
            if(last[C[i]] < i - 1){
                dp[i] = (dp[i - 1] + dp[last[C[i]]]) % MOD;
            } else {
                dp[i] = dp[i - 1];
            }
            last[C[i]] = i;
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}
