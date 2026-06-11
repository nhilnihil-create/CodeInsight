#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i= 0; i< (int)(e); i++)
#define reps(i,s,e) for(int i = s; i < (int)(e); i++)
#define repr(i,s,e) for(int i = s; i > (int)(e); i--)
#define pb push_back
typedef long long ll;
const ll INF = 1LL << 60;
ll bigp = 1000000007;

ll get_num(string s, char c1, char c2, char c3){
    ll l = s.size();
    vector<vector<ll>> dp(3,vector<ll>(l+1));
    reps(i,1,l+1){
        dp[0][i] = dp[0][i-1];
        dp[1][i] = dp[1][i-1];
        dp[2][i] = dp[2][i-1];
        if(s[i-1]==c1){
            dp[0][i] = (dp[0][i-1] + 1)%bigp;
        }
        if(s[i-1]==c2){
            dp[1][i] = (dp[1][i-1] + dp[0][i-1])%bigp;            
        }
        if(s[i-1]==c3){
            dp[2][i] = (dp[2][i-1] + dp[1][i-1])%bigp;            
        }        
    }
    return dp[2][l];
}

ll powmod(ll n, ll m, ll p){
    if(m==0) return 1;
    if(m%2==0){
        ll t = powmod(n, m/2, p);
        return t*t % p;
    }
    return (n * powmod(n, m-1, p))%p;
}

int main()
{
    string s;
    cin >> s;
    ll l = s.size();
    ll ques_num = 0;
    rep(i,l){
        if(s[i]=='?'){ques_num++;}
    }
    ll ans = 0;
    ans =  (ans + get_num(s,'A','B','C') * powmod(3,ques_num,bigp))%bigp;
    if(ques_num >= 1){
        ans = (ans + get_num(s,'A','B','?') * powmod(3,ques_num-1,bigp))%bigp;
        ans = (ans + get_num(s,'A','?','C') * powmod(3,ques_num-1,bigp))%bigp;
        ans = (ans + get_num(s,'?','B','C') * powmod(3,ques_num-1,bigp))%bigp;
    }
    if(ques_num >= 2){
        ans = (ans + get_num(s,'A','?','?') * powmod(3,ques_num-2,bigp))%bigp;
        ans = (ans + get_num(s,'?','B','?') * powmod(3,ques_num-2,bigp))%bigp;
        ans = (ans + get_num(s,'?','?','C') * powmod(3,ques_num-2,bigp))%bigp;
    }
    if(ques_num >= 3){
        ans = (ans + get_num(s,'?','?','?') * powmod(3,ques_num-3,bigp))%bigp;
    }
    cout << ans;
}