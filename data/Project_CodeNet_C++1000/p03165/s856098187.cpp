#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>
#include <vector>
#include <random>
#include <string.h>
#include <stdio.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int, int> ii;
typedef pair<long double, int> id;
typedef pair<long long, long long> llp;
const int N = 3*1e3+1;
int n, m;
long long dp[N][N];
int main() {
    //freopen("ee.inp", "r", stdin);
    //freopen("ee.OUT", "w", stdout);
    fastIO;
    string s, t;
    cin>>s>>t;
    if (s.size()<t.size()) swap(s, t);
    n = s.size(), m = t.size();
    for(int i=1;i<=n;i++) {
        //cout << i << " | ";
        for(int j=1;j<=m;j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if (s[i-1]==t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    stack<int> st;
    while(n>0&&m>0) {
        if (dp[n-1][m]==dp[n][m]) n--;
        else if (dp[n][m-1]==dp[n][m]) m--;
        else if (dp[n-1][m-1]+1==dp[n][m]) {
            n--, m--;
            st.push(n);
        }
    }
    while(!st.empty()) {
        cout << s[st.top()];
        st.pop();
    }
}
