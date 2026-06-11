#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

string s, t;
int dp[3300][3300];
int main(){
    cin >> s >> t;
    int n = s.size(), m = t.size();

    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
        }
    }

    string rewsna = "";

    while(n > 0 && m > 0){
        if(dp[n][m] == dp[n-1][m])n--;
        else if(dp[n][m] == dp[n][m-1])m--;
        else {
            rewsna += s[n-1];
            n--;
            m--;
        }
    }
    int l = rewsna.size();
    for(int i = 0;i < l;i++){
        cout << rewsna[l-i-1];
    }cout << endl;
    
    return 0;
}
