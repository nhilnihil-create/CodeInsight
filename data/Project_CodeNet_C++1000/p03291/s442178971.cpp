#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;



int main()
{
    string s;
    cin >> s;
    
    int t = int(s.length());

    
    ve<ve<ll>> dp(t+1,ve<ll>(4,0));
    
    for (int i = t; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if(i == t){
                dp[i][j] = (j == 3 ? 1 : 0);
            }else{
                dp[i][j] = dp[i+1][j] * (s[i] == '?' ? 3:1);
                if(j < 3 && (s[i]=='?'||s[i]=="ABC"[j])){
                    dp[i][j] += dp[i+1][j+1];
                }
                dp[i][j] %= mod;
            }
            
        }
    }
    out(dp[0][0]);

    return 0;
}
