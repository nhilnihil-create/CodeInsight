#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    //
    vector<vector<int>> A(2, vector<int>(N));
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    vector<vector<int>> dp(2, vector<int>(N));
    dp[0][0]=A[0][0];
    dp[1][0]=A[1][0] + dp[0][0];
    for(int i=1;i<N;i++){
        for(int j=0;j<2;j++){
            if(j==1){
                dp[1][i] = max( dp[1][i-1] , dp[0][i] ) + A[j][i];
            }
            else{
                dp[0][i] = dp[0][i-1] + A[0][i];
            }
        }
    }
    cout << dp[1][N-1] <<endl;
}