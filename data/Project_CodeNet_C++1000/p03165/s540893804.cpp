#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solution(){
    string s,t;
    getline(cin, s);
    getline(cin, t);
    ll n = s.length(); 
    ll m = t.length();
    
    vector<vector<ll> > dp(n+1, vector<ll> (m+1, 0) );
    for(ll i = 1;i <= n;i++){
        for(ll j  = 1;j <= m;j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans = "";
    ll i = n,j = m;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans.insert(ans.begin(), s[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<ans<<"\n";
    return 0;
}

int main(){
    int T = 1; //cin>>T;
    while(T--)
        solution();
    return 0;
}