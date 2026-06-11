#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;

    vector<int> operate;
    operate.push_back(1);
    int num = 6;
    while(num <= n)
    {
        operate.push_back(num);
        num *= 6;
    }
    num = 9;
    while(num <= n)
    {
        operate.push_back(num);
        num *= 9;
    }
    //show(operate);
    vector<int> dp(n+1, MOD);
    dp[0] = 0;
    rep1(i, n){
        int tans = MOD;
        for(auto ope: operate){
            if (ope <= i){
                tans = min(tans, dp[i-ope]+1);
            }
        }
        dp[i] = tans;
    }

    //rep(i, n+1) cout << i << " " << dp[i] << endl;
    cout << dp[n] << endl;

}

