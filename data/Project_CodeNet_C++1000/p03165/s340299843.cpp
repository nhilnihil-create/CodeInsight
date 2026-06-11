#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s, t;

int main(void){
    cin >> s >> t;
    lli m = s.size();
    lli n = t.size();
    vector<vector<lli>> dp(m+1, vector<lli>(n+1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            lli x = 0;
            if(s[i-1] == t[j-1]) x = 1;
            dp[i][j] = max({dp[i-1][j-1]+x, dp[i-1][j], dp[i][j-1]});
        }
    }
    // rep(i, m+1){
    //     rep(j, n+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //cout << dp[m][n] << endl;

    stack<char> st;
    lli i = m;
    lli j = n;
    while(i > 0 && j > 0){
        lli c = dp[i][j];
        if(dp[i-1][j] == c){
            i--;
        }else if(dp[i][j-1] == c){
            j--;
        }else{
            i--;
            j--;
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
    return 0;
}
