#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll MOD = 1000000007;
ll INF =1<<30;
ll dp[110][100100];


int main(){
    int s;
    cin >> s;
    vector<bool> ok (1000000,false);
    int ans = 1;
    ok[s]= true;
    rep(i,10000){
        if(s%2==0){
            s/=2;
            ans++;
            if(ok[s]) {
                cout << ans <<endl;
                return 0;
            }
            ok[s] = true;
        }
        else{
            s = s*3+1;
            ans++;
            if(ok[s]){
                cout << ans <<endl;
                return 0;
            }
            ok[s] = true;
        }
    }
}