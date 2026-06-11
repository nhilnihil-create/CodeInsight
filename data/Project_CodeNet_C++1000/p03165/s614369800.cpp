#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF = 1LL << 60;


int dp[3010][3010];

int main(){
    string s, t;
    cin >> s >> t;

    for(int i = 0; i<s.size(); ++i){
        for(int j = 0; j<t.size(); ++j){
            if(s[i] == t[j]){
                chmax(dp[i+1][j+1] ,dp[i][j] + 1);
            }
            chmax(dp[i+1][j+1], dp[i][j+1]);
            chmax(dp[i+1][j+1], dp[i+1][j]);
        }
    }
    
    int i = (int)s.size();
    int j = (int)t.size();
    string ans = "";

    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }else if(dp[i][j] == dp[i][j-1]){
            j--;
        }else{
            ans = s[i-1] + ans;
            i--;
            j--;
        }
    }
    cout << ans << endl;
}
